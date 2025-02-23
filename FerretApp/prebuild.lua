project "FerretApp"
    mainfile "src/FerretApp.cpp"
    kind "ConsoleApp"

    includedirs
    {
        "$(ROOTDIR)/Ferret/src",
    }

    links
    {
        "Ferret",
    }
