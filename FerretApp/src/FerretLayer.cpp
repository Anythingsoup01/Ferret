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
        ImGui::Begin("Example");
        {
            ImGui::Text("Hello from Ferret!");
            ImGui::End(); // Example
        }
    }

    void ExampleLayer::LogExample()
    {
        Utils::PrintWarning("Printing from MenuBar");
    }
}
