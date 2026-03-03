#pragma once

#include "Ferret/Event/Event.h"

namespace Ferret
{
    class Layer
    {
    public:
        Layer(const std::string& debugName = "debug") : m_DebugName(debugName) {}
        virtual ~Layer() = default;

        virtual void OnAttach() = 0;
        virtual void OnDetach() = 0;
        virtual void OnUpdate(float timeStep) = 0;
        virtual void OnUIRender() = 0;
        virtual void OnEvent(Event& event) = 0;
    private:
        std::string_view m_DebugName;
    };
}
