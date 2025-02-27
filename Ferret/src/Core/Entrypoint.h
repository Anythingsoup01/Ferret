#pragma once


extern Ferret::Application* Ferret::CreateAppliction(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Ferret
{
    int Main(int argc, char** argv)
    {
        while (g_ApplicationRunning)
        {
            Ferret::Application* app = Ferret::CreateAppliction(argc, argv);
            app->Run();
            delete app;
        }
        return 0;
    }
}

int main(int argc, char** argv)
{
    return Ferret::Main(argc, argv);
}
