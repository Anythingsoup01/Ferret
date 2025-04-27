set(SRCS
    src/Ferret/Core/PlatformDetection.cpp
    src/Ferret/Core/Application.cpp
    src/Ferret/Core/Log.cpp
    src/Ferret/Layer/LayerStack.cpp
    src/Ferret/ImGui/ImGuiBuild.cpp
    src/Ferret/ImGui/GUI.cpp
    src/Ferret/Renderer/GraphicsContext.cpp
    src/Ferret/Renderer/RendererAPI.cpp
    src/Ferret/Renderer/RenderCommand.cpp
    src/Ferret/Window/Window.cpp
    src/Platform/OpenGL/ImGui/OpenGLGUI.cpp
    src/Platform/OpenGL/OpenGLGraphicsContext.cpp
    src/Platform/OpenGL/OpenGLRendererAPI.cpp
    src/Platform/GLFW/GLFWInput.cpp
    src/Platform/GLFW/GLFWWindow.cpp
    src/Ferret/Core/Log.h
    src/Ferret/Core/Entrypoint.h
    src/Ferret/Core/Application.h
    src/Ferret/Core/PlatformDetection.h
    src/Ferret/Core/Input.h
    src/Ferret/Core/KeyCodes.h
    src/Ferret/Core/Core.h
    src/Ferret/Layer/LayerStack.h
    src/Ferret/Layer/Layer.h
    src/Ferret/ImGui/GUI.h
    src/Ferret/Event/MouseEvent.h
    src/Ferret/Event/Event.h
    src/Ferret/Event/KeyEvent.h
    src/Ferret/Event/ApplicationEvent.h
    src/Ferret/Renderer/RenderCommand.h
    src/Ferret/Renderer/GraphicsContext.h
    src/Ferret/Renderer/RendererAPI.h
    src/Ferret/Window/Window.h
    src/Platform/OpenGL/OpenGLRendererAPI.h
    src/Platform/OpenGL/ImGui/OpenGLGUI.h
    src/Platform/OpenGL/OpenGLGraphicsContext.h
    src/Platform/GLFW/GLFWWindow.h
    src/Ferret.h
    src/fepch.h
)
add_library(Ferret STATIC ${SRCS})
set_property(TARGET Ferret PROPERTY CXX_STANDARD 17)

target_precompile_headers(Ferret PUBLIC src/fepch.h)
target_include_directories(Ferret PRIVATE
    src
    ${CMAKE_SOURCE_DIR}/Ferret/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/Ferret/vendor/glad/include
    ${CMAKE_SOURCE_DIR}/Ferret/vendor/spdlog/include
    ${CMAKE_SOURCE_DIR}/Ferret/vendor/glm
    ${CMAKE_SOURCE_DIR}/Ferret/vendor/imgui
    ${CMAKE_SOURCE_DIR}/Ferret/vendor/stb
)

target_link_libraries(Ferret
    glfw
    Glad
    GL
    ImGui
    stb
)

target_compile_definitions(Ferret PUBLIC
    FE_RENDERER_OPENGL
    GLFW_INCLUDE_NONE
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
target_compile_definitions(Ferret
PUBLIC
    FE_DEBUG
)
endif(CMAKE_BUILD_TYPE STREQUAL Debug)
if(CMAKE_BUILD_TYPE STREQUAL Release)
target_compile_definitions(Ferret
PUBLIC
    FE_RELEASE
)
endif(CMAKE_BUILD_TYPE STREQUAL Release)
