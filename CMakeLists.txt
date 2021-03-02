cmake_minimum_required(VERSION 3.15)

project(ez-imgui
VERSION 1.0.0
LANGUAGES C CXX)

option(BUILD_TESTS "Build the test executables" ON)

include(GNUInstallDirs)
find_package(ez-cmake CONFIG REQUIRED)

# Find deps
find_package(imgui CONFIG REQUIRED)
find_package(rt-loader CONFIG REQUIRED COMPONENTS glew)
find_package(ez-window CONFIG REQUIRED)

# Create main target.
add_library(ez-imgui STATIC
# Add source files
"src/Context.cpp"
)
# Add the include directory
target_include_directories(ez-imgui PUBLIC 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
target_link_libraries(ez-imgui PUBLIC ez::window ez::input imgui::imgui rt::loader rt::loader-glew)
target_compile_features(ez-imgui PUBLIC cxx_std_17)

# Create backends
add_library(ez-imgui-opengl3 INTERFACE)
target_sources(ez-imgui-opengl3 INTERFACE 
	"$<INSTALL_INTERFACE:lib/backends/opengl3.cpp>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/backends/opengl3.cpp>"
)

add_library(ez-imgui-opengl4 INTERFACE)
target_sources(ez-imgui-opengl4 INTERFACE 
	"$<INSTALL_INTERFACE:lib/backends/opengl4.cpp>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/backends/opengl4.cpp>"
)

add_library(ez-imgui-opengles2 INTERFACE)
target_sources(ez-imgui-opengles2 INTERFACE 
	"$<INSTALL_INTERFACE:lib/backends/opengl_es2.cpp>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/backends/opengl_es2.cpp>"
)

set_target_properties(ez-imgui PROPERTIES EXPORT_NAME "imgui")
set_target_properties(ez-imgui-opengl3 PROPERTIES EXPORT_NAME "imgui-opengl3")
set_target_properties(ez-imgui-opengl4 PROPERTIES EXPORT_NAME "imgui-opengl4")
set_target_properties(ez-imgui-opengles2 PROPERTIES EXPORT_NAME "imgui-opengles2")

# Build the tests once the option is enabled.
if(${BUILD_TESTS})
	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif()

# Set the proper installation path
set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/${CMAKE_PROJECT_NAME})

install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
	TYPE INCLUDE
	FILES_MATCHING
	PATTERN "*.h" PATTERN "*.hpp"
)
install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/backends/"
	DESTINATION "lib/backends/"
	FILES_MATCHING
	PATTERN "*.cpp"
)

install(TARGETS ez-imgui ez-imgui-opengl3
	EXPORT ${CMAKE_PROJECT_NAME}-targets
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}/$<CONFIG>"
	ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}/$<CONFIG>"
	LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/$<CONFIG>"
)

install_package(
	NAME "${CMAKE_PROJECT_NAME}"
	NAMESPACE "ez::"
	EXPORT "${CMAKE_PROJECT_NAME}-targets"
	VERSION "${CMAKE_PROJECT_VERSION}"

	# Version compatiblity
	COMPATIBILITY "SameMajorVersion"

	# Relative install location of the package config files.
	DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/${CMAKE_PROJECT_NAME}"

	# Pre and Post configuration files for the packages. Files are run as scripts when the package is found.
	PRECONFIG "${CMAKE_CURRENT_SOURCE_DIR}/preconfig.cmake"
	#POSTCONFIG "${CMAKE_CURRENT_SOURCE_DIR}/postconfig.cmake"
)