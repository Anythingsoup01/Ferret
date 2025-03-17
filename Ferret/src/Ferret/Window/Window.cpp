#include "fepch.h"
#include "Window.h"

#if defined(FE_PLATFORM_WINDOWS) || defined(FE_PLATFORM_LINUX)
#include "Platform/GLFW/GLFWWindow.h"
#endif

namespace Ferret
{
    Scope<Window> Window::Create(const WindowProps& props)
    {
        switch (PlatformDetection::GetPlatform())
        {
            case PlatformAPI::WINDOWS:
            case PlatformAPI::LINUX:
                return CreateScope<GLFWWindow>(props);

            default:
                FE_API_ASSERT(false, "Current platform not supported!");
                return nullptr;

        }
    }
}
