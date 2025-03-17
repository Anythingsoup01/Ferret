#pragma once

#include "Ferret/ImGui/GUI.h"

namespace Ferret
{
    class OpenGLGUI : public GUI
    {
    public:
        virtual void Init() override;
        virtual void Shutdown() override;

        virtual void NewFrame() override;
        virtual void Render() override;
    };
}
