#include "RendererAPI.h"
#include "Ferret/Core/Utils.h"

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
                Utils::PrintError("NO GRAPHICS API DEFINED!");
                return nullptr;
            }
            case RendererAPI::API::OPENGL:
            {
                return CreateScope<OpenGLRendererAPI>();
            }
            case RendererAPI::API::VULKAN:
            {
                Utils::PrintError("VULCAN NOT SUPPORTED AS OF THIS MOMENT!");
                break;
            }
        }
        Utils::PrintError("OUT OF SCOPE! RendererAPI.cpp");
        return nullptr;
    }
}
