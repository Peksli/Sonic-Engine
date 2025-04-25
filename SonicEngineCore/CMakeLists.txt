cmake_minimum_required(VERSION 3.30)

project(SonicEngineCore)


set(SOURCE_FILES src/Application/Application.cpp

				 src/Managers/LogManager/LogManager.cpp
				 src/Managers/ResourceManager/TextureManager/TextureManager.cpp

				 src/Math/Constants.cpp
				 
				 src/Utils/Utils.cpp)
				 

set(INCLUDE_FILES src/Sonic.h
				  src/Application/Application.h

				  src/Managers/LogManager/LogManager.h
				  src/Managers/EventManager/EventBase.h
				  src/Managers/EventManager/EventManagerMacros.h
				  src/Managers/EventManager/WindowEvent.h
				  src/Managers/ResourceManager/TextureManager/TextureManager.h

				  src/Window/Window.h
				  src/Window/Platform/Windows/WindowsWindow.h	
				  src/Window/Platform/Linux/LinuxWindow.h	
				  src/Window/Platform/Mac/MacWindow.h	

				  src/Math/Constants.h
				  src/Math/Matrices/Matrix2x2.h
				  
				  src/Utils/Utils.h)
				  

# making filters for visual studio --------------------------------------------------------------
source_group(src/Application FILES src/Application/Application.cpp
								   src/Application/Application.h)

source_group(src/Managers/LogManager FILES src/Managers/LogManager/LogManager.cpp
										   src/Managers/LogManager/LogManager.h)

source_group(src/Managers/EventManager FILES src/Managers/EventManager/EventManagerMacros.h
											 src/Managers/EventManager/EventBase.h
											 src/Managers/EventManager/WindowEvent.h)
											 
source_group(src/Managers/ResourceManager/TextureManager FILES src/Managers/ResourceManager/TextureManager/TextureManager.h
															   src/Managers/ResourceManager/TextureManager/TextureManager.cpp)

source_group(src/Window FILES src/Window/Window.h)
source_group(src/Window/Platform/Windows FILES src/Window/Platform/Windows/WindowsWindow.h)
source_group(src/Window/Platform/Linux FILES src/Window/Platform/Linux/LinuxWindow.h)
source_group(src/Window/Platform/Mac FILES src/Window/Platform/Mac/MacWindow.h)

source_group(src/Math FILES src/Math/Constants.h
							src/Math/Constants.cpp)
source_group(src/Math/Matrices FILES src/Math/Matrices/Matrix2x2.h)

source_group(src/Utils FILES src/Utils/Utils.h
							 src/Utils/Utils.cpp)
# -----------------------------------------------------------------------------------------------


add_library(SonicEngine STATIC ${SOURCE_FILES} ${INCLUDE_FILES})

target_include_directories(SonicEngine PUBLIC src 
											  src/Vendor/spdlog/include)

# spdlog
add_subdirectory(src/Vendor/spdlog)
target_link_libraries(SonicEngine PUBLIC spdlog)


# glfw
add_subdirectory(src/Vendor/glfw)
target_link_libraries(SonicEngine PUBLIC glfw)
target_include_directories(SonicEngine PUBLIC src/Vendor/glfw/include)


# glad
# my script already provide a target_include_dirs, so there is no need to include it here
add_subdirectory(src/Vendor/glad)
target_link_libraries(SonicEngine PUBLIC glad)
