set(SRCS
)
add_executable(Test ${SRCS})
set_property(TARGET Test PROPERTY CXX_STANDARD 20)

target_include_directories(Test PRIVATE
    "src"
)

target_link_libraries(Test
    Ferret
)

