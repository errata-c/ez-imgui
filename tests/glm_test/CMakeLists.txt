
add_executable(glm_test "main.cpp")
target_link_libraries(glm_test PRIVATE ez::imgui-opengl3 fmt::fmt)