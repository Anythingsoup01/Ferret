set(SRCS
    "src/Test/TestLayer.h"
    "src/Test/App.cpp"
    "src/Test/TestLayer.cpp"
)
add_executable(Test ${SRCS})
set_property(TARGET Test PROPERTY CXX_STANDARD 20)

target_include_directories(Test PRIVATE
    "src"
    "${CMAKE_SOURCE_DIR}/Ferret/src"
    "${CMAKE_SOURCE_DIR}/vendor/glfw/include"
    "${CMAKE_SOURCE_DIR}/vendor/glad/include"
    "${CMAKE_SOURCE_DIR}/vendor/spdlog/include"
    "${CMAKE_SOURCE_DIR}/vendor/glm"
    "${CMAKE_SOURCE_DIR}/vendor/imgui"
)

target_link_libraries(Test
    Ferret
)

