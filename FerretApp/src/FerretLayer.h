#pragma once

#include "Ferret/Event/Event.h"
#include "Ferret/Event/KeyEvent.h"
#include "Ferret/Layer/Layer.h"

namespace Ferret
{
    class ExampleLayer : public Layer
    {
    public:
        virtual void OnAttach() override;
        virtual void OnDetach() override;

        virtual void OnUpdate(float ts) override;
        virtual void OnUIRender() override;
        virtual void OnEvent(Event& event) override;

        bool OnKeyPressedEvent(KeyPressedEvent& e);

        static ExampleLayer& Get() { return *s_Instance; }

        static void LogExample();

    private:
        static ExampleLayer* s_Instance;
    };
}
