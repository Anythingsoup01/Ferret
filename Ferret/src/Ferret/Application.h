#pragma once

#include <string>
#include <vector>
#include <memory>
#include<functional>

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

    private:
        void Init();
        void Shutdown();

    private:
        ApplicationSpecification m_Specification;

        bool m_Running = false;
    };

    Application* CreateApplication(int argc, char** argv);
}
