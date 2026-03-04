#include "fepch.h"
#include "Serializer.h"

#include <yaml-cpp/yaml.h>

namespace Ferret {

template<>
std::string SerializeItem::Get() {
  char *data = (char *)Data;
  return std::string(data);
}

template<>
void SerializeItem::Set(std::string data) {
  Type = SerializeType::String;
  size_t size = data.length() + 1;
  Data = malloc(size);
  memcpy(Data, data.data(), size);
}

static std::string SerializeTypeToString(const SerializeType& type) {
  switch (type) {
    case SerializeType::Bool:    return "Bool";
    case SerializeType::Float:   return "Float";
    case SerializeType::Double:  return "Double";
    case SerializeType::Int16:   return "Int16";
    case SerializeType::Int32:   return "Int32";
    case SerializeType::Int64:   return "Int64";
    case SerializeType::UInt16:  return "UInt16";
    case SerializeType::UInt32:  return "UInt32";
    case SerializeType::UInt64:  return "UInt64";
    case SerializeType::String:  return "String";
    default:                     return "Unknown";
  }
}

SerializeType SerializeTypeFromString(const std::string& str) {
    if (str == "Bool")   return SerializeType::Bool;
    if (str == "Float")  return SerializeType::Float;
    if (str == "Double") return SerializeType::Double;
    if (str == "Int16")  return SerializeType::Int16;
    if (str == "Int32")  return SerializeType::Int32;
    if (str == "Int64")  return SerializeType::Int64;
    if (str == "UInt16") return SerializeType::UInt16;
    if (str == "UInt32") return SerializeType::UInt32;
    if (str == "UInt64") return SerializeType::UInt64;
    if (str == "String") return SerializeType::String;

    // Default fallback
    return SerializeType::None; 
}

void Serializer::Serialize(const SerializeContainer &items, const std::filesystem::path &savePath) {
  YAML::Emitter out;

  out << YAML::Key << "Objects" << YAML::Value << YAML::BeginSeq;

  for (auto& item : items.Items) {
    out << YAML::BeginMap;
    out << YAML::Key << "Name" << YAML::Value << item.Name;
    out << YAML::Key << "Data" << YAML::Value;
    switch (item.Type) {
      case SerializeType::Bool:
        out << *(bool*)item.Data;
        break;
      case SerializeType::Float:
        out << *(float*)item.Data;
        break;
      case SerializeType::Double:
        out << *(double*)item.Data;
        break;
      case SerializeType::Int16:
        out << *(int16_t*)item.Data;
        break;
      case SerializeType::Int32:
        out << *(int32_t*)item.Data;
        break;
      case SerializeType::Int64:
        out << *(int64_t*)item.Data;
        break;
      case SerializeType::UInt16:
        out << *(uint16_t*)item.Data;
        break;
      case SerializeType::UInt32:
        out << *(uint32_t*)item.Data;
        break;
      case SerializeType::UInt64:
        out << *(uint64_t*)item.Data;
        break;
      case SerializeType::String:
        out << (char*)item.Data;
        break;
      default:
        out << YAML::Null;
        break;
    }
    out << YAML::Key << "Type" << YAML::Value << SerializeTypeToString(item.Type);
    out << YAML::EndMap;
  }

  out << YAML::EndSeq;

  std::ofstream fout(savePath);
  fout << out.c_str();
}

SerializeContainer Serializer::Deserialize(const std::filesystem::path &loadPath) {
  SerializeContainer ctnr;

  YAML::Node data;
  try	{ data = YAML::LoadFile(loadPath); }
  catch (YAML::ParserException ex)
  {
    FE_API_ERROR("Failed to load .catengine file '{0}'\n       {1}", loadPath.string(), ex.what());
    return {};
  }

  auto objects = data["Objects"];
  if (!objects)
    return {};

  for (auto obj : objects) {
    SerializeItem item = SerializeItem(obj["Name"].as<std::string>());
    SerializeType type = SerializeTypeFromString(obj["Type"].as<std::string>());
    switch (type) {
      case SerializeType::Bool:
        item.Set(obj["Data"].as<bool>());
        break;
      case SerializeType::Float:
        item.Set(obj["Data"].as<float>());
        break;
      case SerializeType::Double:
        item.Set(obj["Data"].as<double>());
        break;
      case SerializeType::Int16:
        item.Set(obj["Data"].as<int16_t>());
        break;
      case SerializeType::Int32:
        item.Set(obj["Data"].as<int32_t>());
        break;
      case SerializeType::Int64:
        item.Set(obj["Data"].as<int64_t>());
        break;
      case SerializeType::UInt16:
        item.Set(obj["Data"].as<uint16_t>());
        break;
      case SerializeType::UInt32:
        item.Set(obj["Data"].as<uint32_t>());
        break;
      case SerializeType::UInt64:
        item.Set(obj["Data"].as<uint64_t>());
        break;
      case SerializeType::String:
        item.Set(obj["Data"].as<std::string>());
        break;
      default:
        FE_API_ASSERT(false, "INVALID DATA TYPE");
        break;
    }

    ctnr.Items.push_back(std::move(item));
  }

  return ctnr;
}


}
