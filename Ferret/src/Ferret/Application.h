#pragma once

#include <string>
#include <vector>
#include <memory>
#include<functional>

struct GLFWwindow;

namespace Ferret
{
    struct ApplicationSpecification
    {
        std::string Name = "Ferret App";
        uint32_t Width = 1280;
        uint32_t Height = 720;
    };

    class Application
    {
    public:
        Application(const ApplicationSpecification& specs);
        ~Application();

        static Application& Get();

        void Run();

        void Close();

        float GetTime() { return m_TimeStep; }

        GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }
    private:
        void Init();
        void Shutdown();

    private:
        ApplicationSpecification m_Specification;
        GLFWwindow* m_WindowHandle = nullptr;
        bool m_Running = false;

        float m_TimeStep = 0.0f;
        float m_FrameTime = 0.0f;
        float m_LastFrameTime = 0.0f;

    };
    // Implemented by Client
    Application* CreateApplication(int argc, char** argv);
}
