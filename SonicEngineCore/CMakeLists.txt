cmake_minimum_required(VERSION 3.30)

project(SonicEngineCore)


set(SOURCE_FILES src/application/Application.cpp

				 src/managers/LogManager/LogManager.cpp

				 src/math/Constants.cpp)
				 

set(INCLUDE_FILES src/Sonic.h
				  src/application/Application.h

				  src/managers/LogManager/LogManager.h
				  src/managers/EventManager/EventBase.h
				  src/managers/EventManager/EventManagerMacros.h
				  src/managers/EventManager/WindowEvent.h

				  src/Window/Window.h
				  src/Window/Platform/Windows/WindowsWindow.h	
				  src/Window/Platform/Linux/LinuxWindow.h	
				  src/Window/Platform/Mac/MacWindow.h	

				  src/math/Constants.h
				  src/math/Matrices/Matrix2x2.h)
				  

# making filters for visual studio --------------------------------------------------------------
source_group(src/Application FILES src/application/Application.cpp
								   src/application/Application.h)

source_group(src/managers/LogManager FILES src/managers/LogManager/LogManager.cpp
										   src/managers/LogManager/LogManager.h)

source_group(src/managers/EventManager FILES src/managers/EventManager/EventManagerMacros.h
											 src/managers/EventManager/EventBase.h
											 src/managers/EventManager/WindowEvent.h)

source_group(src/math FILES src/math/Constants.h
							src/math/Constants.cpp)

source_group(src/Window FILES src/Window/Window.h)
source_group(src/Window/Platform/Windows FILES src/Window/Platform/Windows/WindowsWindow.h)
source_group(src/Window/Platform/Linux FILES src/Window/Platform/Linux/LinuxWindow.h)
source_group(src/Window/Platform/Mac FILES src/Window/Platform/Mac/MacWindow.h)

source_group(src/math/Matrices FILES src/math/Matrices/Matrix2x2.h)
# -----------------------------------------------------------------------------------------------


add_library(SonicEngine STATIC ${SOURCE_FILES} ${INCLUDE_FILES})

target_include_directories(SonicEngine PUBLIC src 
											  src/application
											  src/managers
											  src/Window
											  src/vendor/spdlog/include)

# spdlog
add_subdirectory(src/vendor/spdlog)
target_link_libraries(SonicEngine PUBLIC spdlog)


# glfw
add_subdirectory(src/vendor/glfw)
target_link_libraries(SonicEngine PUBLIC glfw)
target_include_directories(SonicEngine PUBLIC src/vendor/glfw/include)


# glad
# my script already provide a target_include_dirs, so there is no need to include it here
add_subdirectory(src/vendor/glad)
target_link_libraries(SonicEngine PUBLIC glad)
