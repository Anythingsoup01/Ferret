project "Ferret"
    language "C++"
    dialect "17"
    kind "StaticLib"

    files
    {
        "src/Ferret/Core/Application.cpp",
        "src/Ferret/Core/Application.h",
        "src/Ferret/Core/Entrypoint.h",
        "src/Ferret/Core/Layer.h",
        "src/Ferret/Core/Utils.h",
        "src/Ferret/Core/Utils.cpp",
        "src/Ferret/Input/Input.cpp",
        "src/Ferret/Input/Input.h",
        "src/Ferret/Input/KeyCodes.h",
        "src/Ferret/ImGui/ImGuiBuild.cpp",
        "src/Ferret/ImGui/FerretGui.cpp",
        "src/Ferret/ImGui/FerretGui.h",
        "src/Ferret/Renderer/RendererAPI.cpp",
        "src/Ferret/Renderer/RendererAPI.h",
        "src/Ferret/Renderer/RenderCommand.cpp",
        "src/Ferret/Renderer/RenderCommand.h",
        "src/Platform/OpenGL/OpenGLRendererAPI.cpp",
        "src/Platform/OpenGL/OpenGLRendererAPI.h",
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
