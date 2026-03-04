#include "Ferret/Core/Application.h"
#include "Ferret/Core/Entrypoint.h"
#include "TestLayer.h"
#include "imgui.h"

// To object orientate a layer
// you must define it out of
// the scope, or pass it in
// to the lambda.
// Either works without a hitch!

Ferret::Application* Ferret::CreateApplication(int argc, char** argv)
{
    Ferret::ApplicationSpecifications spec;
    spec.Title = "Test Application";

    Ferret::Application* app = new Ferret::Application(spec);

    app->PushLayer(new TestLayer);
    app->SetMenubarCallback([app]()
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Exit"))
            {
                app->Close();
            }

            ImGui::EndMenu();
        }
    });

    return app;
}
