#pragma once
#include "Core.h"
#include "KeyCodes.h"

namespace Ferret
{
    class Input
    {
    protected:
        Input() = default;
    public:
        Input(const Input&) = delete;
        Input& operator=(const Input&) = delete;

        static bool IsKeyPressed(KeyCode keycode);
        static bool IsKeyReleased(KeyCode keycode);

        static bool IsMouseButtonPressed(MouseButton button);
        static bool IsMouseButtonReleased(MouseButton button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();

        static float GetMouseXOffset();
        static float GetMouseYOffset();

        static void ResetMouseOffset() { m_MouseOffsetX = 0; m_MouseOffsetY = 0; }

    private:
        static inline float m_MouseOffsetX = 0, m_MouseOffsetY = 0;
    };
}
