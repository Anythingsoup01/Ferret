project "Ferret"
    language "C++"
    dialect "17"
    kind "StaticLib"

    pch "src/fepch.h"

    files
    {
        "src/*.cpp",
        "src/*.h",
    }

    includedirs
    {
        "src",
        "$(WORKSPACEDIR)/Ferret/vendor/glfw/include",
        "$(WORKSPACEDIR)/Ferret/vendor/glad/include",
        "$(WORKSPACEDIR)/Ferret/vendor/spdlog/include",
        "$(WORKSPACEDIR)/Ferret/vendor/glm",
        "$(WORKSPACEDIR)/Ferret/vendor/imgui",
        "$(WORKSPACEDIR)/Ferret/vendor/stb",
    }

    links
    {
        "glfw",
        "Glad",
        "GL",
        "ImGui",
        "stb"
    }

    defines
    {
        "FE_RENDERER_OPENGL",
        "GLFW_INCLUDE_NONE"
    }

    filter "configurations:Debug"
        defines "FE_DEBUG"

    filter "configurations:Release"
        defines "FE_RELEASE"

