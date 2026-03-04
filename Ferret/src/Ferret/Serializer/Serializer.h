#pragma once

namespace Ferret {

enum class SerializeType {
  None = 0,
  Bool,
  Float, Double,
  Int16, Int32, Int64,
  UInt16, UInt32, UInt64,
  String,
};

struct SerializeItem {
  std::string Name;
  void* Data;
  SerializeType Type;


  SerializeItem(const std::string& name)
    : Name(name), Data(nullptr), Type(SerializeType::None) {}

  template<typename T>
  T Get() {
    return *static_cast<T*>(Data);
  }


  template<typename T>
  void Set(T data) {
    if constexpr (std::is_same_v<T, bool>) {
        Type = SerializeType::Bool;
    } else if constexpr (std::is_same_v<T, float>) {
        Type = SerializeType::Float;
    } else if constexpr (std::is_same_v<T, double>) {
        Type = SerializeType::Double;
    } else if constexpr (std::is_same_v<T, int16_t>) {
        Type = SerializeType::Int16;
    } else if constexpr (std::is_same_v<T, int32_t>) {
        Type = SerializeType::Int32;
    } else if constexpr (std::is_same_v<T, int64_t>) {
        Type = SerializeType::Int64;
    } else if constexpr (std::is_same_v<T, uint16_t>) {
        Type = SerializeType::UInt16;
    } else if constexpr (std::is_same_v<T, uint32_t>) {
        Type = SerializeType::UInt32;
    } else if constexpr (std::is_same_v<T, uint64_t>) {
        Type = SerializeType::UInt64;
    } else if constexpr (std::is_same_v<T, std::string>) {
        Type = SerializeType::String;
    }

    Data = malloc(sizeof(T));
    memcpy(Data, &data, sizeof(T));
  }
};

struct SerializeContainer {
  std::vector<SerializeItem> Items;
};


class Serializer {
public:
  static void Serialize(const SerializeContainer& items, const std::filesystem::path& savePath);
  static SerializeContainer Deserialize(const std::filesystem::path& loadPath);
};

}
