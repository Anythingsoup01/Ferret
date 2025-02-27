project "Ferret"
    language "C++"
    dialect "17"
    kind "StaticLib"

    files
    {
        "src/Core/Application.cpp",
        "src/Core/Application.h",
        "src/Core/Entrypoint.h",
        "src/Core/Layer.h",
        "src/Core/Input/Input.cpp",
        "src/Core/Input/Input.h",
        "src/Core/Input/KeyCodes.h",
        "src/Core/ImGui/ImGuiBuild.cpp",
        "src/Core/Utils.cpp",
        "src/Core/Utils.h",
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
