cmake_minimum_required(VERSION 3.10)

project(cway VERSION 1.0)

file(GLOB_RECURSE SOURCES ./src/*.c)

configure_file(./includes/config.h.in ./includes/config.h)

add_executable(cway ${SOURCES})

target_include_directories(cway PUBLIC "${PROJECT_SOURCE_DIR}/includes", "${PROJECT_BINARY_DIR}/includes")
