#include <iostream>

#include <ez/imgui.hpp>

#include <ez/window/Window.hpp>
#include <ez/window/BasicEngine.hpp>

#include <rt/loader.hpp>

class BasicWindow : public ez::window::Window {
public:
	BasicWindow(std::string_view _title, glm::ivec2 size, ez_window::Style _style, const ez_window::RenderSettings& rs)
		: Window(_title, size, _style, rs)
		, v2(0.f)
		, v3(0.f)
		, v4(0.f)

		, iv2(0)
		, iv3(0)
		, iv4(0)
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
		setActive(true);

		context.makeActive();
		context.newFrame(*this);

		if (ImGui::Begin("Hello, world!")) {
			ImGui::Text("Testing out the basic floating point vector functions.");

			ImGui::InputVec("glm::vec2", v2);

			ImGui::InputVec("glm::vec3", v3);

			ImGui::InputVec("glm::vec4", v4);
		}
		ImGui::End();



		ImGuiIO& io = ImGui::GetIO();
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
		glClearColor(0.823, 0.870, 0.913, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		context.render();
	}
private:
	glm::vec2 v2;
	glm::vec3 v3;
	glm::vec4 v4;

	glm::ivec2 iv2;
	glm::ivec3 iv3;
	glm::ivec4 iv4;

	ez::imgui::Context context;
};

int main(int argc, char** argv) {
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