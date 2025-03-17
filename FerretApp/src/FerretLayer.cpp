#include "FerretLayer.h"
#include "Ferret.h"
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

    void ExampleLayer::OnUpdate(float ts)
    {

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

    void ExampleLayer::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(ExampleLayer::OnKeyPressedEvent));
    }

    bool ExampleLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        bool ctrl = Input::IsKeyPressed(KeyCode::RightControl) || Input::IsKeyPressed(KeyCode::LeftControl);

        switch (e.GetKeyCode())
        {
            case KeyCode::C:
            {
                if (ctrl)
                    FE_CLI_INFO("Ctrl + C Pressed");
                else
                    FE_CLI_INFO("C Pressed");
                break;
            }
            default:
                break;
        }
        return false;
    }

    void ExampleLayer::LogExample()
    {
        FE_CLI_INFO("Logging from MenuBar");
    }
}
