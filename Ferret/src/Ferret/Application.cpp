#include "Application.h"


#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

static Ferret::Application* s_Instance = nullptr;

extern bool g_ApplicationRunning;

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

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
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
        {
            std::cerr << "Could not initialize GLFW!\n";
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        m_WindowHandle = glfwCreateWindow(m_Specification.Width, m_Specification.Height, m_Specification.Name.c_str(), NULL, NULL);


    }

    void Application::Shutdown()
    {

    }

    void Application::Run()
    {
        m_Running = true;

        while (!glfwWindowShouldClose(m_WindowHandle) && m_Running)
        {
            glfwPollEvents();

            // Update layers


        }
    }
}
