#pragma once

#include <mutex>

#include "Core.h"

#include "Ferret/Event/Event.h"
#include "Ferret/Event/ApplicationEvent.h"

#include "Ferret/ImGui/GUI.h"

#include "Ferret/Layer/LayerStack.h"

#include "Ferret/Window/Window.h"


struct GLFWwindow;

namespace Ferret
{
    struct ApplicationSpecifications
    {
        std::string Title;
        uint32_t Width = 1280;
        uint32_t Height = 720;
    };

    class Application
    {
    public:
        Application(const ApplicationSpecifications& specification = ApplicationSpecifications());
        ~Application();

        static Application& Get() { return *s_Instance; }

        void Run();

        void OnEvent(Event& e);

        void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }

        void PushLayer(Layer* layer);

        void Close();

        bool OnWindowClose(WindowCloseEvent& e);

        float GetTime();
        Window& GetWindow() const { return *m_Window; }

        void SubmitToMainThread(const std::function<void()>& function);

    private:
        void Init();
        void Shutdown();
        void ExecuteMainThreadQueue();

    private:
        ApplicationSpecifications m_Specification;
        bool m_Running = false;
        Scope<Window> m_Window;
        Scope<GUI> m_GUI;

        float m_TimeStep = 0.0f;
        float m_FrameTime = 0.0f;
        float m_LastFrameTime = 0.0f;

        LayerStack m_LayerStack;
        std::function<void()> m_MenubarCallback;

        std::vector<std::function<void()>> m_MainThreadQueue;
        std::mutex m_MainThreadQueueMutex;


        static Application* s_Instance;
    };

    Application* CreateApplication(int argc, char** argv);

}
