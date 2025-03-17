#include "fepch.h"
#include "GraphicsContext.h"

#include "Ferret/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLGraphicsContext.h"

namespace Ferret {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {

        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::NONE:    FE_API_ASSERT(false, "NO GRAPHICS API DEFINED!"); return nullptr;
            case RendererAPI::API::OPENGL:  return CreateScope<OpenGLGraphicsContext>(static_cast<GLFWwindow*>(window));
            default: FE_API_ASSERT(false, "RENDERERAPI NOT SUPPORTED!") return nullptr;
        }

    }

}
