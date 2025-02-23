add_library(Ferret STATIC src/Ferret/Application.cpp ${SRCS})

target_include_directories(Ferret PRIVATE
    src
)


