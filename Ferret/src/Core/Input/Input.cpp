#include "Input.h"

#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace Ferret
{
    bool Input::IsKeyDown(KeyCode keycode)
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
        int state = glfwGetKey(windowHandle, (int)keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
    static bool IsMouseButtonDown(MouseButton button)
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
        int state = glfwGetMouseButton(windowHandle, (int)button);
        return state == GLFW_PRESS;
    }

    static glm::vec2 GetMousePosition()
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();

        double x, y;
        glfwGetCursorPos(windowHandle, &x, &y);
        return { (float)x, (float)y };
    }

    static void SetCursorMode(CursorMode mode)
    {
        GLFWwindow* windowHandle = Application::Get().GetWindowHandle();
        glfwSetInputMode(windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)mode);
    }
}
