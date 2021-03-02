#include <iostream>

#include <ez/imgui/Context.hpp>
#include <ez/window/Window.hpp>
#include <ez/window/BasicEngine.hpp>

#include <imgui.h>
#include <rt/loader.hpp>

class BasicWindow : public ez::window::Window {
public:
	BasicWindow(std::string_view _title, glm::ivec2 size, ez_window::Style _style, const ez_window::RenderSettings& rs)
		: Window(_title, size, _style, rs)
		, context(*this)
	{
		bool result = rt::load();
		assert(result);

		ImGui::StyleColorsDark();
	}

	void handleInput() override {
		// make the ImGui context active
		context.makeActive();
		
		ez::InputEvent ev;
		while (pollInput(ev)) {
			context.processEvent(ev);
			if (ev.type == ez::InEv::Closed) {
				close();
				// Window will not be destroyed until full frame cycle is complete.
			}
		}
	}

	void draw() override {
		// make the ImGui context active
		context.makeActive();

		// Make the opengl context active
		setActive(true);

		context.newFrame(*this);

		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}

		// 3. Show another simple window.
		if (show_another_window)
		{
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

		ImGuiIO& io = ImGui::GetIO();
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		context.render();
	}
private:
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	float f = 0.0f;
	int counter = 0;


	ez::imgui::Context context;
};

int main(int argc, char ** argv) {
	ez::window::BasicEngine engine;

	ez_window::GLSettings gset;
	gset.majorVersion() = 4;
	gset.minorVersion() = 5;
	gset.depthBits() = 24;
	gset.stencilBits() = 8;

	BasicWindow* window = new BasicWindow("basic_test", { 800, 600 }, ez_window::StylePreset::Default, gset);
	engine.add(window);

	return engine.run(argc, argv);
}