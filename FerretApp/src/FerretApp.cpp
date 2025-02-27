#include "Core/Application.h"
#include "Core/Entrypoint.h"
#include "imgui.h"
class ExampleLayer : public Ferret::Layer
{
public:
    const char* test = "";
    virtual void OnUIRender() override
    {
        ImGui::ShowDemoWindow();
        ImGui::Begin("Example");
        ImGui::End();
    }
};



Ferret::Application* Ferret::CreateAppliction(int argc, char** argv)
{
    Ferret::ApplicationSpecifications spec;
    spec.Title = "Ferret Example";

    Ferret::Application* app = new Ferret::Application(spec);
    app->PushLayer<ExampleLayer>();
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
