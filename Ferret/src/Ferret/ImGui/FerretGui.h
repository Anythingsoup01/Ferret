#pragma once

namespace Ferret
{
    class FerretGui
    {
    public:
        static void Init();
        static void Shutdown();
        static void Update();

        static void Render();

        static void SetStyle();
    };
}
