project "Ferret"
    mainfile "src/Ferret/Application.cpp"
    kind "StaticLib"

    includedirs
    {
        "src",

        "$(ROOTDIR)/vendors/GLFW/include",
    }

    links
    {
        "glfw",
    }
