project "FerretApp"
    language "C++"
    dialect "17"
    kind "ConsoleApp"

    files
    {
        "src/FerretApp.cpp",
        "src/FerretLayer.cpp",
        "src/FerretLayer.h",
    }

    includedirs
    {
        "$(ROOTDIR)/Ferret/src",
        "$(ROOTDIR)/vendor/glfw/include",
        "$(ROOTDIR)/vendor/glad/include",
        "$(ROOTDIR)/vendor/glm",
        "$(ROOTDIR)/vendor/imgui",
    }

    links
    {
        "Ferret"
    }
