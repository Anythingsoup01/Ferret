#pragma once
#include "Ferret/Core/Core.h"
#include <filesystem>

namespace Ferret
{

	class Texture
	{
	public:

		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
        virtual uint32_t GetRendererID() const = 0;

        virtual void SetData(const uint8_t* data, uint32_t width, uint32_t height) = 0;
    };

    class Texture2D : public Texture
    {
    public:
        static Ref<Texture2D> Create(const std::filesystem::path& filePath);
        static Ref<Texture2D> Create(const uint8_t* data, uint32_t width, uint32_t height);

    };
}
