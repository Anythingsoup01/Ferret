#include "fepch.h"
#include "OpenGLTexture2D.h"

#include "stb_image.h"


namespace Ferret
{
    OpenGLTexture2D::OpenGLTexture2D(const std::filesystem::path& filePath)
    {
        int width, height, channels;

        void* data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);

        if (channels == 3)
        {
            m_InternalFormat = GL_RGB8;
            m_DataFormat = GL_RGB;
        }
        else
        {
            m_InternalFormat = GL_RGBA8;
            m_DataFormat = GL_RGBA;
        }


        glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
        glTextureStorage2D(m_RendererID, 1, m_InternalFormat, width, height);

        glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);

        glTextureSubImage2D(m_RendererID, 0, 0, 0, width, height, m_DataFormat, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }
    OpenGLTexture2D::OpenGLTexture2D(const uint8_t* data, uint32_t width, uint32_t height)
    {
        m_InternalFormat = GL_RGBA8;
        m_DataFormat = GL_BGRA;

        glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
        glTextureStorage2D(m_RendererID, 1, m_InternalFormat, width, height);

        glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);

        glTextureSubImage2D(m_RendererID, 0, 0, 0, width, height, m_DataFormat, GL_UNSIGNED_BYTE, data);

    }

    void OpenGLTexture2D::SetData(const uint8_t* data, uint32_t width, uint32_t height)
    {
        glTextureSubImage2D(m_RendererID, 0, 0, 0, width, height, m_DataFormat, GL_UNSIGNED_BYTE, data);
    }


    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &m_RendererID);
    }


}
