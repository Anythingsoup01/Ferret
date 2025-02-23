add_executable(FerretApp src/FerretApp.cpp ${SRCS})

target_include_directories(FerretApp PRIVATE
    ${CMAKE_SOURCE_DIR}/Ferret/src
)

target_link_libraries(FerretApp
    Ferret
)


