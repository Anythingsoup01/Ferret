#pragma once
#include "Ferret/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Ferret
{

    class OpenGLGraphicsContext : public GraphicsContext {
    public:
        OpenGLGraphicsContext(GLFWwindow* windowHandle);
        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow* m_Window;
    };
}
