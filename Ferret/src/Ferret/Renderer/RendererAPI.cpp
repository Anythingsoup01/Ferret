#include "fepch.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

#if !defined(FE_RENDERER_OPENGL) || !defined (FE_RENDERER_VULKAN)
#define FE_RENDERER_OPENGL
#endif

namespace Ferret
{
#   ifdef FE_RENDERER_OPENGL
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::OPENGL;
#   elif defined(FE_RENDERER_VULKAN)
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::VULKAN;
#   else
    RendererAPI::API RendererAPI::s_API = RendererAPI::API::NONE;
#   endif

    Scope<RendererAPI>RendererAPI::Create()
    {
        switch (s_API)
        {
            case RendererAPI::API::NONE:
            {
                FE_API_ASSERT(false, "NO GRAPHICS API DEFINED!");
                return nullptr;
            }
            case RendererAPI::API::OPENGL:
            {
                return CreateScope<OpenGLRendererAPI>();
            }
            case RendererAPI::API::VULKAN:
            {
                FE_API_ASSERT(false, "NO GRAPHICS API DEFINED!");
                break;
            }
            default:
                FE_API_ASSERT(false, "OUT OF SCOPE!");
                return nullptr;
        }
        return nullptr;
    }
}
