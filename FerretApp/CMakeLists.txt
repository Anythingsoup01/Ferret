set(SRCS
    src/FerretApp.cpp
)
add_executable(FerretApp ${SRCS})
set_property(TARGET FerretApp PROPERTY CXX_STANDARD 17)

target_include_directories(FerretApp PRIVATE
    ${CMAKE_SOURCE_DIR}/Ferret/src
    ${CMAKE_SOURCE_DIR}/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
    ${CMAKE_SOURCE_DIR}/vendor/glm
    ${CMAKE_SOURCE_DIR}/vendor/imgui
)

target_link_libraries(FerretApp
    Ferret
)

