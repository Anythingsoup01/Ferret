#include "TestLayer.h"
#include "Ferret.h"

#include "Ferret/Serializer/Serializer.h"

#include "imgui.h"

namespace Ferret
{

static SerializeContainer s_Container;

void TestLayer::OnAttach()
{
  #if 1
  // String
  SerializeItem stringItem = SerializeItem("StringData");
  std::string sData = "This is my DATA!";
  stringItem.Set(sData);

  // Boolean
  SerializeItem boolItem = SerializeItem("EnabledState");
  bool bData = true;
  boolItem.Set(bData);

  // Floating Point
  SerializeItem floatItem = SerializeItem("Velocity");
  float fData = 12.5f;
  floatItem.Set(fData);

  SerializeItem doubleItem = SerializeItem("PrecisionValue");
  double dData = 3.1415926535;
  doubleItem.Set(dData);

  // Signed Integers
  SerializeItem int16Item = SerializeItem("ShortInt");
  int16_t i16Data = -32000;
  int16Item.Set(i16Data);

  SerializeItem int32Item = SerializeItem("StandardInt");
  int32_t i32Data = 100000;
  int32Item.Set(i32Data);

  SerializeItem int64Item = SerializeItem("BigInt");
  int64_t i64Data = 9000000000000000000;
  int64Item.Set(i64Data);

  // Unsigned Integers
  SerializeItem uInt16Item = SerializeItem("UShortInt");
  uint16_t u16Data = 65000;
  uInt16Item.Set(u16Data);

  SerializeItem uInt32Item = SerializeItem("UStandardInt");
  uint32_t u32Data = 4000000000;
  uInt32Item.Set(u32Data);

  SerializeItem uInt64Item = SerializeItem("UBigInt");
  uint64_t u64Data = 18000000000000000000ULL;
  uInt64Item.Set(u64Data);

  s_Container.Items.push_back(std::move(stringItem));
  s_Container.Items.push_back(std::move(boolItem));
  s_Container.Items.push_back(std::move(floatItem));
  s_Container.Items.push_back(std::move(doubleItem));
  s_Container.Items.push_back(std::move(int16Item));
  s_Container.Items.push_back(std::move(int32Item));
  s_Container.Items.push_back(std::move(int64Item));
  s_Container.Items.push_back(std::move(uInt16Item));
  s_Container.Items.push_back(std::move(uInt32Item));
  s_Container.Items.push_back(std::move(uInt64Item));
  #else
  s_Container = Serializer::Deserialize(".save_path");
  #endif
}

void TestLayer::OnDetach()
{
  Serializer::Serialize(s_Container, ".save_path");
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
