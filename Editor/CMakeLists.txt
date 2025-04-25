cmake_minimum_required(VERSION 3.30)

project(SonicEngineEditor)

set(CMAKE_CXX_STANADARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES src/main.cpp)

source_group(src FILES src/main.cpp)

add_executable(SonicEngineEditor ${SOURCE_FILES})

target_link_libraries(SonicEngineEditor PRIVATE SonicEngine)