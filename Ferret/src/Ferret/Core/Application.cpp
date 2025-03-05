#include "Application.h"

#include "Ferret/Renderer/RenderCommand.h"
#include "Ferret/ImGui/FerretGui.h"

#include <GLFW/glfw3.h>

#include "Utils.h"
#include "imgui.h"

#include <glm/glm.hpp>

extern bool g_ApplicationRunning;

namespace Ferret
{
    Application* Application::s_Instance = nullptr;

    Application::Application(const ApplicationSpecifications& specification)
        :m_Specification(specification)
    {
        s_Instance = this;
        Init();
    }

    Application::~Application()
    {
        Shutdown();
        s_Instance = nullptr;
    }

    void Application::Init()
    {
        if (!glfwInit())
        {
            Utils::PrintError("Could not load GLFW!");
            return;
        }
        m_WindowHandle = glfwCreateWindow(m_Specification.Width, m_Specification.Height, m_Specification.Title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_WindowHandle);

        RenderCommand::Init();

        FerretGui::Init();

    }

    void Application::Shutdown()
    {
        for (auto& layer : m_LayerStack)
            layer->OnDetach();
        m_LayerStack.clear();

        FerretGui::Shutdown();

        glfwDestroyWindow(m_WindowHandle);
        glfwTerminate();

        g_ApplicationRunning = false;
    }

    void Application::Run()
    {
        m_Running = true;

        ImGuiIO& io = ImGui::GetIO();

        while (!glfwWindowShouldClose(m_WindowHandle) && m_Running)
        {
            glfwPollEvents();
            glfwSwapBuffers(m_WindowHandle);

            RenderCommand::Clear(glm::vec4(0,0,0,1));

            for (auto& layer : m_LayerStack)
                layer->OnUpdate(m_TimeStep);

            FerretGui::Update();

            static bool dockspaceOpen = true;
            static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

            ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

            {
                const ImGuiViewport* viewport = ImGui::GetMainViewport();
                ImGui::SetNextWindowPos(viewport->WorkPos);
                ImGui::SetNextWindowSize(viewport->WorkSize);
                ImGui::SetNextWindowViewport(viewport->ID);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
                ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
                window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
                window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
            }

            if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
                window_flags |= ImGuiWindowFlags_NoBackground;

            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
            ImGui::Begin("MyDockSpace", &dockspaceOpen, window_flags);
            ImGui::PopStyleVar(3);
            {
                // Submit the DockSpace
                ImGuiIO& io = ImGui::GetIO();
                if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
                {
                    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
                    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
                }
                ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });

                for (auto& layer : m_LayerStack)
                    layer->OnUIRender();


                ImGui::PopStyleVar();

                if (m_MenubarCallback)
                {
                    ImGui::BeginMenuBar();
                    {
                        m_MenubarCallback();
                        ImGui::EndMenuBar();
                    }
                }
            }
            ImGui::End();

            // Rendering
            FerretGui::Render();

            ExecuteMainThreadQueue();

        }

    }

    void Application::Close()
    {
        m_Running = false;
    }

    float Application::GetTime()
    {
        return (float)glfwGetTime();
    }

    void Application::SubmitToMainThread(const std::function<void()>& function)
    {
        m_MainThreadQueue.emplace_back(function);
    }

    void Application::ExecuteMainThreadQueue()
    {
        std::vector<std::function<void()>> copy;
        {
            std::scoped_lock<std::mutex> lock(m_MainThreadQueueMutex);
            copy = m_MainThreadQueue;
            m_MainThreadQueue.clear();
        }


        for (auto& function : copy)
            function();
    }
}
