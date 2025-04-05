cmake_minimum_required(VERSION 3.30)

project(SonicEngineCore)

set(SOURCE_FILES src/Application.cpp
				 src/managers/LogManager/LogManager.cpp)
				 
set(INCLUDE_FILES src/Sonic.h
				  src/Application.h
				  src/managers/LogManager/LogManager.h)
				  
# making filters for visual studio
source_group(src FILES src/Application.cpp
					   src/Application.h)
source_group(src/managers/LogManager FILES src/managers/LogManager/LogManager.cpp
										   src/managers/LogManager/LogManager.h)

add_library(SonicEngine STATIC ${SOURCE_FILES} ${INCLUDE_FILES})

target_include_directories(SonicEngine PUBLIC src 
											  src/managers
											  src/vendor/spdlog/include)

add_subdirectory(src/vendor/spdlog)
target_link_libraries(SonicEngine PUBLIC spdlog)