#include "TestLayer.h"
#include "Ferret.h"
#include "imgui.h"

namespace Ferret
{
void TestLayer::OnAttach()
{
}

void TestLayer::OnDetach()
{
}

void TestLayer::OnUpdate(float ts)
{

}


void TestLayer::OnUIRender()
{
  ImGui::Begin("##MAINPAGE");
  {
    ImGui::Text("Welcome to Ferret");

    ImGui::End();
  }

  ImGui::ShowDemoWindow();
}

void TestLayer::OnEvent(Event& e)
{
  EventDispatcher dispatcher(e);

  dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(TestLayer::OnKeyPressedEvent));
}

bool TestLayer::OnKeyPressedEvent(KeyPressedEvent& e)
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


}
