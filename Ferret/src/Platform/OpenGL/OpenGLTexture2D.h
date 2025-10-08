#pragma once

#include <glad/glad.h>
#include "Ferret/Renderer/Texture.h"

namespace Ferret
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::filesystem::path& filePath);
		OpenGLTexture2D(const uint8_t* data, uint32_t width, uint32_t height);
		~OpenGLTexture2D();


		virtual uint32_t GetWidth() const override { return m_Width; };
		virtual uint32_t GetHeight() const override { return m_Height; };
        virtual uint32_t GetRendererID() const override { return m_RendererID; }

        void SetData(const uint8_t* data, uint32_t width, uint32_t height) override;


    private:
        bool m_IsLoaded = false;
        GLenum m_InternalFormat, m_DataFormat;\
        uint32_t m_Width, m_Height;
        uint32_t m_RendererID;
    };
}
