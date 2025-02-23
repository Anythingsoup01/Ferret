add_library(Ferret STATIC src/Ferret/Application.cpp ${SRCS})

target_include_directories(Ferret PRIVATE
    src
    ${CMAKE_SOURCE_DIR}/vendors/GLFW/include
)

target_link_libraries(Ferret
    glfw
)


