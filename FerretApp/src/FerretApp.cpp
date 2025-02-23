#include "Ferret/Application.h"

#define FE_PLATFORM_LINUX

#include "Ferret/Entrypoint.h"

Ferret::Application* Ferret::CreateApplication(int argc, char** argv)
{
    Ferret::ApplicationSpecification spec;
    spec.Name = "Ferret Example";

    Ferret::Application* app = new Ferret::Application(spec);

    return app;
}
