#include "fepch.h"
#include "Application.h"

#include "Ferret/Core/Core.h"
#include "Ferret/Event/ApplicationEvent.h"
#include "Ferret/Event/Event.h"
#include "Ferret/Renderer/RenderCommand.h"

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
        PlatformDetection::Init();

        m_Window = Window::Create(WindowProps(m_Specification.Title, m_Specification.Width, m_Specification.Height));
        m_Window->SetVSync(true);
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

        m_GUI = GUI::Create();

        Init();

    }

    Application::~Application()
    {
        Shutdown();
        s_Instance = nullptr;
    }

    void Application::Init()
    {
        m_GUI->Init();
    }

    void Application::Shutdown()
    {
        m_GUI->Shutdown();
        g_ApplicationRunning = false;
    }

    void Application::Run()
    {
        m_Running = true;

        ImGuiIO& io = ImGui::GetIO();

        while (m_Running)
        {
            m_Window->OnUpdate();
            RenderCommand::Clear(glm::vec4(0,0,0,1));

            for (auto& layer : m_LayerStack)
                layer->OnUpdate(m_TimeStep);

            m_GUI->NewFrame();

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

                for (Layer* layer : m_LayerStack)
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
            m_GUI->Render();

            ExecuteMainThreadQueue();

        }

    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            if (e.Handled)
                break;
            (*it)->OnEvent(e);
        }
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }


    void Application::Close()
    {
        m_Running = false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    float Application::GetTime()
    {
        return m_Window->GetTime();
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
