#include "fepch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Ferret
{
    void OpenGLRendererAPI::Clear(const glm::vec4& clearColor)
    {
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}
