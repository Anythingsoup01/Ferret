#include "fepch.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

#if !defined(FE_RENDERER_OPENGL) && !defined(FE_RENDERER_VULKAN)
#define FE_RENDERER_OPENGL
#endif

namespace Ferret
{
#   ifdef FE_RENDERER_OPENGL
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OPENGL;
#   endif

    Scope<RendererAPI>RendererAPI::Create()
    {
        switch (s_API)
        {
            case RendererAPI::API::NONE:    FE_API_ASSERT(false, "NO GRAPHICS API DEFINED!"); return nullptr;
            case RendererAPI::API::OPENGL:  return CreateScope<OpenGLRendererAPI>();
            default: FE_API_ASSERT(false, "RENDERERAPI NOT SUPPORTED!") return nullptr;
        }
    }
}
