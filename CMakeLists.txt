cmake_minimum_required(VERSION 3.15)

project(EZ_IMGUI
VERSION 0.4.1
LANGUAGES C CXX
)

include(GNUInstallDirs)
include("cmake/ez-cmake/install_package.cmake")

option(BUILD_TESTS "Build the test executables" ON)
option(SEPARATE_DIRECTORY "Install the package into its own directory" ON)
set(CONFIG_DIR "${CMAKE_INSTALL_DATAROOTDIR}/ez-imgui" CACHE STRING "The relative directory to install package config files.")



option(BUILD_OPENGL2 "Build and install the opengl2 backend" ON)
option(BUILD_OPENGL3 "Build and install the opengl3 backend" ON)
option(BUILD_OPENGL4 "Build and install the opengl3 backend" ON)

set(TARGET_LIST "ez-imgui")

# Find deps
find_package(imgui CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(rt-loader CONFIG REQUIRED COMPONENTS glew)

find_package(ez-window CONFIG REQUIRED)
find_package(ez-math CONFIG REQUIRED)
find_package(ez-bitflags CONFIG REQUIRED)
find_package(ez-geo CONFIG REQUIRED)

add_library(ez-imgui STATIC
	"src/Context.cpp"
	"src/VecFunctions.cpp"
	"src/Item.cpp"

	"src/layout/Padding.cpp"
	"src/layout/Enumerators.cpp"
	"src/layout/Anchor.cpp"

	"src/containers/FlexBox.cpp"
)
target_include_directories(ez-imgui PUBLIC 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>"
)
target_link_libraries(ez-imgui PUBLIC 
	ez::window 
	ez::math
	ez::geo

	imgui::imgui 
	rt::loader-glew 
	fmt::fmt
)

target_compile_features(ez-imgui PUBLIC cxx_std_17)
add_library(ez::imgui ALIAS ez-imgui)
set_target_properties(ez-imgui PROPERTIES EXPORT_NAME "imgui")


if(BUILD_OPENGL4)
	find_package(rt-core CONFIG REQUIRED)

endif()

# Create backends
if(BUILD_OPENGL3)
	list(APPEND TARGET_LIST "ez-imgui-opengl3")

	add_library(ez-imgui-opengl3 STATIC
		"src/backends/opengl3.cpp"
	)
	target_link_libraries(ez-imgui-opengl3 PUBLIC ez::imgui)

	set_target_properties(ez-imgui-opengl3 PROPERTIES EXPORT_NAME "imgui-opengl3")
	add_library(ez::imgui-opengl3 ALIAS ez-imgui-opengl3)
endif()

if(BUILD_OPENGL2)
	list(APPEND TARGET_LIST "ez-imgui-opengl2")

	add_library(ez-imgui-opengl2 STATIC
		"src/backends/opengl2.cpp"
	)
	target_link_libraries(ez-imgui-opengl2 PUBLIC ez::imgui)

	set_target_properties(ez-imgui-opengl2 PROPERTIES EXPORT_NAME "imgui-opengl2")
	add_library(ez::imgui-opengl2 ALIAS ez-imgui-opengl2)
endif()



if(BUILD_TESTS)
	add_subdirectory("tests")
endif()

if(SEPARATE_DIRECTORY)
	set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/ez-imgui)
endif()



install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
	TYPE INCLUDE
	FILES_MATCHING
	PATTERN "*.h" PATTERN "*.hpp"
)

install(TARGETS ${TARGET_LIST}
    EXPORT "ez-imgui-export"
    PUBLIC_HEADER DESTINATION "include"
    ARCHIVE DESTINATION "lib/$<CONFIG>"
    LIBRARY DESTINATION "lib/$<CONFIG>"
    RUNTIME DESTINATION "bin/$<CONFIG>"
)

install_package(
	NAME "ez-imgui"
	NAMESPACE "ez::"
	EXPORT "ez-imgui-export"
	VERSION "${EZ_IMGUI_VERSION}"
	COMPATIBILITY "SameMajorVersion"
	DESTINATION "${CONFIG_DIR}"
	PRECONFIG "cmake/preconfig.cmake"
)