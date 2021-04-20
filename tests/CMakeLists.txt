cmake_minimum_required(VERSION 3.15)

project(EZ_IMGUI_TESTS
VERSION 0.1.0
LANGUAGES C CXX)

find_package(rt-loader CONFIG REQUIRED COMPONENTS glew)
find_package(ez-window CONFIG REQUIRED)

add_subdirectory("basic_test")

add_subdirectory("glm_test")

add_subdirectory("layout_test")