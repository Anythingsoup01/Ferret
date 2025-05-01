#pragma once

#include "Ferret/Renderer/RendererAPI.h"

namespace Ferret
{
    class VulkanRendererAPI : public RendererAPI
    {
        // This will initialize vulkan
        void Clear(const glm::vec4& clearColor) {}
    };
}
