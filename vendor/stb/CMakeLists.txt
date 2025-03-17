set(SRCS
    stb_image.cpp
    stb_image.h
)
add_library(stb STATIC ${SRCS})
set_property(TARGET stb PROPERTY CXX_STANDARD 17)

