set(SRCS
    src/Core/Application.cpp
    src/Core/Application.h
    src/Core/Entrypoint.h
    src/Core/Layer.h
    src/Core/Input/Input.cpp
    src/Core/Input/Input.h
    src/Core/Input/KeyCodes.h
    src/Core/ImGui/ImGuiBuild.cpp
    src/Core/Utils.cpp
    src/Core/Utils.h
)
add_library(Ferret STATIC ${SRCS})
set_property(TARGET Ferret PROPERTY CXX_STANDARD 17)

target_include_directories(Ferret PRIVATE
    src
    ${CMAKE_SOURCE_DIR}/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
    ${CMAKE_SOURCE_DIR}/vendor/glm
    ${CMAKE_SOURCE_DIR}/vendor/imgui
)

target_link_libraries(Ferret
    glfw
    Glad
    GL
    ImGui
)

