#pragma once

namespace Ferret
{
    class GUI
    {
    public:
        virtual ~GUI() = default;
        virtual void Init() = 0;
        virtual void Shutdown() = 0;

        virtual void NewFrame() = 0;
        virtual void Render() = 0;

        static Scope<GUI> Create();
    };
}
