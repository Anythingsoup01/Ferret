workspace "Ferret"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

external "Ferret"
external "FerretApp"

external "vendor/glfw"
external "vendor/glad"
external "vendor/imgui"
external "vendor/stb"
external "vendor/prebuild"
