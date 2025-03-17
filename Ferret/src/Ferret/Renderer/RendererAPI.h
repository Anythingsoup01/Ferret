#pragma once
#include "Ferret/Core/Core.h"
#include <glm/glm.hpp>

namespace Ferret
{
    class RendererAPI
    {
    public:
        enum class API
        {
            NONE = 0,
            OPENGL = 1,
        };
    public:
        virtual ~RendererAPI() = default;

        virtual void Clear(const glm::vec4& clearColor) = 0;

        static API GetAPI() { return s_API; }
        static Scope<RendererAPI> Create();
    private:
        static API s_API;
    };
}
