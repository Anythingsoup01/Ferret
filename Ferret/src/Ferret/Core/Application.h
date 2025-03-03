#pragma once

#include "Layer.h"
#include "Core.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <mutex>

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
        void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }

        template<typename T>
        void PushLayer()
        {
            static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
            m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
        }

        void PushLayer(const Ref<Layer>& layer) { m_LayerStack.emplace_back(layer); layer->OnAttach(); }

        void Close();

        float GetTime();
        GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }

        void SubmitToMainThread(const std::function<void()>& function);

    private:
        void Init();
        void Shutdown();
        void ExecuteMainThreadQueue();

    private:
        ApplicationSpecifications m_Specification;
        GLFWwindow* m_WindowHandle = nullptr;
        bool m_Running = false;

        float m_TimeStep = 0.0f;
        float m_FrameTime = 0.0f;
        float m_LastFrameTime = 0.0f;

        std::vector<Ref<Layer>> m_LayerStack;
        std::function<void()> m_MenubarCallback;

        std::vector<std::function<void()>> m_MainThreadQueue;
        std::mutex m_MainThreadQueueMutex;


        static Application* s_Instance;
    };

    Application* CreateApplication(int argc, char** argv);

}
