#include "OpenGLRendererAPI.h"
#include "Ferret/Core/Utils.h"

#include <GLFW/glfw3.h>

namespace Ferret
{
    void OpenGLRendererAPI::Clear(const glm::vec4& clearColor)
    {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
