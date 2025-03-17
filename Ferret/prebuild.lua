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
        "$(WORKSPACEDIR)/vendor/glfw/include",
        "$(WORKSPACEDIR)/vendor/glad/include",
        "$(WORKSPACEDIR)/vendor/spdlog/include",
        "$(WORKSPACEDIR)/vendor/glm",
        "$(WORKSPACEDIR)/vendor/imgui",
        "$(WORKSPACEDIR)/vendor/stb",
    }

    links
    {
        "glfw",
        "Glad",
        "GL",
        "ImGui",
        "stb"
    }

    filter "configurations:Debug"
        defines "FE_DEBUG"

    filter "configurations:Release"
        defines "FE_Release"

    filter "system:windows"
        defines "FE_PLATFORM_WINDOWS"

    filter "system:linux"
        defines "FE_PLATFORM_LINUX"
