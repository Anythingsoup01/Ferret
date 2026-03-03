#include "fepch.h"
#include "Texture.h"

#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLTexture2D.h"

namespace Ferret
{
    Ref<Texture2D> Texture2D::Create(const std::filesystem::path& filePath)
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::OPENGL: return CreateRef<OpenGLTexture2D>(filePath);
            default: FE_API_ASSERT(false, "CatEngine Headless not supported!"); return nullptr;
        }
    }

    Ref<Texture2D> Texture2D::Create(const uint8_t* data, uint32_t width, uint32_t height)
    {
        switch (RendererAPI::GetAPI())
        {
            case RendererAPI::API::OPENGL: return CreateRef<OpenGLTexture2D>(data, width, height);
            default: FE_API_ASSERT(false, "CatEngine Headless not supported!"); return nullptr;
        }
    }
}
