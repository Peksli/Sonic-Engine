cmake_minimum_required(VERSION 3.30)

project(glad)

set(SOURCE_FILES src/glad.c)
set(INCLUDE_FILES include/glad/glad.h)

add_library(glad STATIC ${SOURCE_FILES} ${INCLUDE_FILES})

target_include_directories(glad PUBLIC include)