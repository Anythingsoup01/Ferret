cmake_minimum_required(VERSION 3.30.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Ferret)


add_subdirectory(Ferret)
add_subdirectory(FerretApp)

add_subdirectory(vendors/GLFW)
