
#include "GraphicsContext.h"

#include "Ferret/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLGraphicsContext.h"

namespace Ferret {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {

        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::NONE:    FE_API_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OPENGL:  return CreateScope<OpenGLGraphicsContext>(static_cast<GLFWwindow*>(window));
            default:
                return nullptr;
        }

    }

}
