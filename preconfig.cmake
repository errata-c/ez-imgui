
if(NOT TARGET imgui::imgui)
	find_dependency(imgui CONFIG)
endif()

if(NOT TARGET ez::input)
	find_dependency(ez-input CONFIG)
endif()

if(NOT TARGET ez::glcompat)
	find_dependency(ez-glcompat CONFIG)
endif()

if(NOT TARGET ez::window)
	find_dependency(ez-window CONFIG)
endif()



