#include "OpenGLRendererAPI.h"
#include "Ferret/Core/Utils.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Ferret
{
    void OpenGLRendererAPI::Init()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            Utils::PrintError("Could not load GLAD!");
            return;
        }
    }

    void OpenGLRendererAPI::Clear(const glm::vec4& clearColor)
    {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
