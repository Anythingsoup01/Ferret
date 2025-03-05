#pragma once
#include "Ferret/Renderer/RendererAPI.h"

namespace Ferret
{
    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void Clear(const glm::vec4& clearColor);
    };
}
