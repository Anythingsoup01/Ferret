Project =
{
    name = "Ferret",
    language = "C++",
    dialect = "17",
    kind = "StaticLib",

    pch = "src/fepch.h",

    files =
    {
        "src/*.cpp",
        "src/*.h",
        "../vendor/stb/stb_image.cpp",
        "../vendor/stb/stb_image.h",
        "../vendor/glm/glm/*.hpp"
    },

    includedirs =
    {
        "src",
        "../vendor/glfw/include",
        "../vendor/glad/include",
        "../vendor/spdlog/include",
        "../vendor/imgui",
        "../vendor/stb",
    },

    links =
    {
        "glfw",
        "Glad",
        "GL",
        "ImGui",
        "vulkan",
    },

    defines =
    {
        "FE_RENDERER_OPENGL",
    },

    filters =
    {
        {
            name = "configurations:Debug",
            defines = "FE_DEBUG"
        },
        {
            name = "configurations:Release",
            defines = "FE_RELEASE",
        }
    },
}
