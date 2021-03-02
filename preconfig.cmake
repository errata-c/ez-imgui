
if(NOT TARGET imgui::imgui)
	find_dependency(imgui CONFIG)
endif()

if(NOT TARGET ez::input)
	find_dependency(ez-input CONFIG)
endif()

if(NOT TARGET rt::loader)
	find_dependency(rt-loader CONFIG)
endif()

if(NOT TARGET ez::window)
	find_dependency(ez-window CONFIG)
endif()



