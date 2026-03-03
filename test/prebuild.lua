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
    "src"
  },

  links = {
    "Ferret"
  }
}
