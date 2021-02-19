
add_executable(basic_test "main.cpp")
target_link_libraries(basic_test PRIVATE GLEW::GLEW ez::window ez-imgui ez-imgui-opengl3)