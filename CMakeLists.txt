cmake_minimum_required(VERSION 3.30.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Ferret LANGUAGES C CXX)
set(GDEFINES
)

add_subdirectory(vendor/imgui)
add_subdirectory(vendor/glad)
add_subdirectory(FerretApp)
add_subdirectory(Ferret)
add_subdirectory(vendor/glfw)
