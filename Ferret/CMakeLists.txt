set(SRCS
    src/Ferret/Core/Utils.cpp
    src/Ferret/Core/Application.cpp
    src/Ferret/Layer/LayerStack.cpp
    src/Ferret/ImGui/FerretGui.cpp
    src/Ferret/ImGui/ImGuiBuild.cpp
    src/Ferret/Renderer/GraphicsContext.cpp
    src/Ferret/Renderer/RendererAPI.cpp
    src/Ferret/Renderer/RenderCommand.cpp
    src/Platform/Linux/LinuxInput.cpp
    src/Platform/Linux/LinuxWindow.cpp
    src/Platform/OpenGL/OpenGLGraphicsContext.cpp
    src/Platform/OpenGL/OpenGLRendererAPI.cpp
    src/Ferret/Core/Utils.h
    src/Ferret/Core/Platform.h
    src/Ferret/Core/Window.h
    src/Ferret/Core/Entrypoint.h
    src/Ferret/Core/Application.h
    src/Ferret/Core/Input.h
    src/Ferret/Core/KeyCodes.h
    src/Ferret/Core/Core.h
    src/Ferret/Layer/LayerStack.h
    src/Ferret/Layer/Layer.h
    src/Ferret/ImGui/FerretGui.h
    src/Ferret/Event/MouseEvent.h
    src/Ferret/Event/Event.h
    src/Ferret/Event/KeyEvent.h
    src/Ferret/Event/ApplicationEvent.h
    src/Ferret/Renderer/RenderCommand.h
    src/Ferret/Renderer/GraphicsContext.h
    src/Ferret/Renderer/RendererAPI.h
    src/Platform/Linux/LinuxWindow.h
    src/Platform/OpenGL/OpenGLRendererAPI.h
    src/Platform/OpenGL/OpenGLGraphicsContext.h
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

