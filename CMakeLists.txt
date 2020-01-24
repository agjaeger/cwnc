cmake_minimum_required(VERSION 3.10)

# set the project name
project(
    cwnc
    VERSION 1.0.0
)

# add the executable
add_executable(
    cwnc
    source/main.c
    source/parser.c
)

target_include_directories(
    cwnc
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC include/
)
