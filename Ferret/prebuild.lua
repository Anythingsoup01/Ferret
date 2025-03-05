project "Ferret"
    language "C++"
    dialect "17"
    kind "StaticLib"

    files
    {
        "src/*.cpp",
        "src/*.h"
    }

    includedirs
    {
        "src",
        "$(ROOTDIR)/vendor/glfw/include",
        "$(ROOTDIR)/vendor/glad/include",
        "$(ROOTDIR)/vendor/glm",
        "$(ROOTDIR)/vendor/imgui",
    }

    links
    {
        "glfw",
        "Glad",
        "GL",
        "ImGui"
    }
