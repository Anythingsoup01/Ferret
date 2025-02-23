project "FerretApp"
    mainfile "src/FerretApp.cpp"
    kind "ConsoleApp"

    includedirs
    {
        "$(ROOTDIR)/vendors/GLFW/include",

        "$(ROOTDIR)/Ferret/src",
    }

    links
    {
        "Ferret",
    }
