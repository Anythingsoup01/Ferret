#pragma once
#include "RendererAPI.h"

#include <glm/glm.hpp>

#include "Ferret/Core/Core.h"

namespace Ferret
{
    class RenderCommand
    {
    public:
        static inline void Clear(const glm::vec4& clearColor)
        {
            s_RendererAPI->Clear(clearColor);
        }

    private:
        static Scope<RendererAPI> s_RendererAPI;
    };
}
