#include "Application.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Utils.h"
#include "imgui.h"

#include <glm/glm.hpp>

extern bool g_ApplicationRunning;

namespace Ferret
{
    static Application* s_Instance;

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

    Application& Application::Get()
    {
        return *s_Instance;
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

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            Utils::PrintError("Could not load GLAD!");
            return;
        }


        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;


        // ImGui Style
        ImGui::StyleColorsDark();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplGlfw_InitForOpenGL(m_WindowHandle, true);
        ImGui_ImplOpenGL3_Init("#version 430");
    }

    void Application::Shutdown()
    {
        for (auto& layer : m_LayerStack)
            layer->OnDetach();
        m_LayerStack.clear();

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

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
            glClear(GL_COLOR_BUFFER_BIT);

            for (auto& layer : m_LayerStack)
                layer->OnUpdate(m_TimeStep);

            ImGui_ImplGlfw_NewFrame();
            ImGui_ImplOpenGL3_NewFrame();
            ImGui::NewFrame();
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
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                GLFWwindow* backup_current_context = glfwGetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                glfwMakeContextCurrent(backup_current_context);
            }

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
}
