#include "FerretLayer.h"
#include "Ferret/Core/Utils.h"
#include "imgui.h"

namespace Ferret
{
    ExampleLayer* ExampleLayer::s_Instance = nullptr;

    void ExampleLayer::OnAttach()
    {
        s_Instance = this;
    }

    void ExampleLayer::OnDetach()
    {
        s_Instance = nullptr;
    }

    void ExampleLayer::OnUIRender()
    {
        ImGui::Begin("##MAINPAGE");
        {
            ImGui::Text("Welcome to Ferret");

            ImGui::End();
        }

        ImGui::ShowDemoWindow();
    }

    void ExampleLayer::LogExample()
    {
        Utils::PrintWarning("Printing from MenuBar");
    }
}
