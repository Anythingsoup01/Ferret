#include "Ferret/Core/Application.h"
#include "Ferret/Core/Entrypoint.h"
#include "FerretLayer.h"
#include "imgui.h"


Ferret::Application* Ferret::CreateApplication(int argc, char** argv)
{
    Ferret::ApplicationSpecifications spec;
    spec.Title = "Ferret Example";

    Ferret::Application* app = new Ferret::Application(spec);
    app->PushLayer<Ferret::ExampleLayer>();
    // Future reference, you shouldn't make multiple of the same //
    // layer if you intend on using static functions in the menu //
    // bar, it may cause issues. To resolve this, I will try to  //
    // work on letting users push object orientated layers       //
    // ie. Ferret::ExampleLayer exampleLayer;                    //
    //     app->PushLayer(exampleLayer);                         //
    // It is officially added to the list of things to do!       //
    app->SetMenubarCallback([app]()
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Example"))
            {
                // Do static function here
                Ferret::ExampleLayer::Get().LogExample();
            }
            if (ImGui::MenuItem("Exit"))
            {
                app->Close();
            }

            ImGui::EndMenu();
        }
    });

    return app;
}
