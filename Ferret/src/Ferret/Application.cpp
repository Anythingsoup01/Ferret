#include "Application.h"

#include <iostream>

static Ferret::Application* s_Instance = nullptr;

namespace Ferret
{
    Application::Application(const ApplicationSpecification& specification)
        : m_Specification(specification)
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
        std::cout << "Application Initialized!\n";
    }

    void Application::Shutdown()
    {

    }

    void Application::Run()
    {
        m_Running = true;
        while (m_Running)
        {

        }
    }
}
