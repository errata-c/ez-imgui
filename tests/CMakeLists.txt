cmake_minimum_required(VERSION 3.15)

project(ez-imgui-tests 
VERSION 1.0.0
LANGUAGES C CXX)

find_package(rt-loader CONFIG REQUIRED COMPONENTS glew)
find_package(ez-window CONFIG REQUIRED)

add_subdirectory("basic_test")