set(SRCS
    src/FerretLayer.cpp
    src/FerretApp.cpp
    src/FerretLayer.h
)
add_executable(FerretApp ${SRCS})
set_property(TARGET FerretApp PROPERTY CXX_STANDARD 17)

target_include_directories(FerretApp PRIVATE
    ${CMAKE_SOURCE_DIR}/Ferret/src
    ${CMAKE_SOURCE_DIR}/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/vendor/glad/include
    ${CMAKE_SOURCE_DIR}/vendor/spdlog/include
    ${CMAKE_SOURCE_DIR}/vendor/glm
    ${CMAKE_SOURCE_DIR}/vendor/imgui
)

target_link_libraries(FerretApp
    Ferret
)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
target_compile_definitions(FerretApp
PUBLIC
    FE_DEBUG
)
endif(CMAKE_BUILD_TYPE STREQUAL Debug)
if(CMAKE_BUILD_TYPE STREQUAL Release)
target_compile_definitions(FerretApp
PUBLIC
    FE_RELEASE
)
endif(CMAKE_BUILD_TYPE STREQUAL Release)
