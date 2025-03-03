#pragma once
#include "Ferret/Core/Layer.h"

namespace Ferret
{
    class ExampleLayer : public Layer
    {
    public:
        virtual void OnAttach();
        virtual void OnDetach();

        virtual void OnUpdate(float ts) {}
        virtual void OnUIRender();

        static ExampleLayer& Get() { return *s_Instance; }

        static void LogExample();

    private:
        static ExampleLayer* s_Instance;
    };
}
