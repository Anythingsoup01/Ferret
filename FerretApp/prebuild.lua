project "FerretApp"
    language "C++"
    dialect "17"
    kind "ConsoleApp"

    files
    {
        "src/*.cpp",
        "src/*.h",
    }

    includedirs
    {
        "$(WORKSPACEDIR)/Ferret/src",
        "$(WORKSPACEDIR)/vendor/glfw/include",
        "$(WORKSPACEDIR)/vendor/glad/include",
        "$(WORKSPACEDIR)/vendor/spdlog/include",
        "$(WORKSPACEDIR)/vendor/glm",
        "$(WORKSPACEDIR)/vendor/imgui",
    }

    links
    {
        "Ferret",
    }

    filter "configurations:Debug"
        defines "FE_DEBUG"

    filter "configurations:Release"
        defines "FE_RELEASE"

