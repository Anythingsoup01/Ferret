#include "fepch.h"
#include "GUI.h"

#include "Ferret/Renderer/RendererAPI.h"
#include "Platform/OpenGL/ImGui/OpenGLGUI.h"

namespace Ferret
{
    Scope<GUI> GUI::Create()
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::NONE: FE_API_ASSERT(false, "NO RENDER API SET!"); return nullptr;
            case RendererAPI::API::OPENGL: return CreateScope<OpenGLGUI>();
            default: FE_API_ASSERT(false, "RENDER API NOT SUPPORTED!") return nullptr;
        }
    }
}
