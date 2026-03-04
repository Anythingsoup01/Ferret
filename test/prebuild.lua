-- This is a test application that isn't compiled naturally and needs manual inclusion to compile
Project = {
  name = "Test",
  kind = "ConsoleApp",
  language = "C++",
  dialect = "20",

  files = {
    "src/*.h",
    "src/*.cpp",
  },

  includedirs = {
    "src",
    "${WORKSPACEDIR}Ferret/src",
    "${WORKSPACEDIR}vendor/glfw/include",
    "${WORKSPACEDIR}vendor/glad/include",
    "${WORKSPACEDIR}vendor/spdlog/include",
    "${WORKSPACEDIR}vendor/glm",
    "${WORKSPACEDIR}vendor/imgui",
  },

  links = {
    "Ferret"
  }
}
