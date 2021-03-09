#include "ez/imgui/Context.hpp"
#include "imgui.h"
#include <cinttypes>
#include <cassert>
#include <memory>
#include <array>
#include <iostream>

#include <ez/window/Core.hpp>
#include <ez/window/Cursor.hpp>
#include <ez/window/Window.hpp>

static std::unique_ptr<std::array<ez::window::Cursor, 9>> cursors;

namespace ezwin = ez::window;

namespace ez::imgui {
	Context::Context()
		: ctx(nullptr)
		, mousePress{false, false, false}
	{
		ImGui::CreateContext();
		ctx = ImGui::GetCurrentContext();

		assert(ctx != nullptr);

		ImGuiIO& io = ImGui::GetIO();
		io.BackendPlatformName = "ez-window";

		io.KeyMap[ImGuiKey_Tab] = static_cast<int32_t>(ez::Key::Tab);
		io.KeyMap[ImGuiKey_LeftArrow] = static_cast<int32_t>(ez::Key::Left);
		io.KeyMap[ImGuiKey_RightArrow] = static_cast<int32_t>(ez::Key::Right);
		io.KeyMap[ImGuiKey_UpArrow] = static_cast<int32_t>(ez::Key::Up);
		io.KeyMap[ImGuiKey_DownArrow] = static_cast<int32_t>(ez::Key::Down);
		io.KeyMap[ImGuiKey_PageUp] = static_cast<int32_t>(ez::Key::PageUp);
		io.KeyMap[ImGuiKey_PageDown] = static_cast<int32_t>(ez::Key::PageDown);
		io.KeyMap[ImGuiKey_Home] = static_cast<int32_t>(ez::Key::Home);
		io.KeyMap[ImGuiKey_End] = static_cast<int32_t>(ez::Key::End);
		io.KeyMap[ImGuiKey_Insert] = static_cast<int32_t>(ez::Key::Insert);
		io.KeyMap[ImGuiKey_Delete] = static_cast<int32_t>(ez::Key::Delete);
		io.KeyMap[ImGuiKey_Backspace] = static_cast<int32_t>(ez::Key::Backspace);
		io.KeyMap[ImGuiKey_Space] = static_cast<int32_t>(ez::Key::Space);
		io.KeyMap[ImGuiKey_Enter] = static_cast<int32_t>(ez::Key::Enter);
		io.KeyMap[ImGuiKey_Escape] = static_cast<int32_t>(ez::Key::Escape);
		io.KeyMap[ImGuiKey_KeyPadEnter] = static_cast<int32_t>(ez::Key::KPEnter);
		io.KeyMap[ImGuiKey_A] = static_cast<int32_t>(ez::Key::A);
		io.KeyMap[ImGuiKey_C] = static_cast<int32_t>(ez::Key::C);
		io.KeyMap[ImGuiKey_V] = static_cast<int32_t>(ez::Key::V);
		io.KeyMap[ImGuiKey_X] = static_cast<int32_t>(ez::Key::X);
		io.KeyMap[ImGuiKey_Y] = static_cast<int32_t>(ez::Key::Y);
		io.KeyMap[ImGuiKey_Z] = static_cast<int32_t>(ez::Key::Z);

		if (!cursors) {
			cursors.reset(new std::array<window::Cursor, 9>{
				window::Cursor(window::SystemCursor::Arrow),
				window::Cursor(window::SystemCursor::IBeam),
				window::Cursor(window::SystemCursor::SizeAll),
				window::Cursor(window::SystemCursor::SizeV),

				window::Cursor(window::SystemCursor::SizeH),
				window::Cursor(window::SystemCursor::SizeFDiag),
				window::Cursor(window::SystemCursor::SizeBDiag),
				window::Cursor(window::SystemCursor::Hand),

				window::Cursor(window::SystemCursor::Disabled)
			});
		}

		backend.init();
	}

	Context::~Context() {
		if (ctx) {
			backend.shutdown();
			ImGui::DestroyContext(ctx);
			ctx = nullptr;
		}
	}

	void Context::makeActive() {
		ImGui::SetCurrentContext(ctx);
	}
	bool Context::isActive() const {
		return ImGui::GetCurrentContext() == ctx;
	}

	bool Context::processEvent(const ez::InputEvent& ev) {

		ImGuiIO& io = ImGui::GetIO();
		switch (ev.type) {
		case ez::InEv::Char:
			io.AddInputCharacter(ev.codepoint);
			return true;

		case ez::InEv::MousePress:
			switch (ev.mouse.button) {
			case ez::Mouse::Left:
				mousePress[0] = true;
				return true;
			case ez::Mouse::Middle:
				mousePress[1] = true;
				return true;
			case ez::Mouse::Right:
				mousePress[2] = true;
				return true;
			default:
				return false;
			}

		case ez::InEv::Scroll:
			if (ev.scroll.x > 0) io.MouseWheelH += 1;
			if (ev.scroll.x < 0) io.MouseWheelH -= 1;
			if (ev.scroll.y > 0) io.MouseWheel += 1;
			if (ev.scroll.y < 0) io.MouseWheel -= 1;
			return true;

		case ez::InEv::KeyRelease:
		case ez::InEv::KeyPress: {
			uint32_t key = static_cast<uint32_t>(ev.key.code);
			assert(key < IM_ARRAYSIZE(io.KeysDown));
			io.KeysDown[key] = (ev.type == ez::InEv::KeyPress);
			io.KeyShift = ev.key.mods.isPressed(ez::KeyMod::Shift);
			io.KeyCtrl = ev.key.mods.isPressed(ez::KeyMod::Ctrl);
			io.KeyAlt = ev.key.mods.isPressed(ez::KeyMod::Alt);
#ifdef _WIN32
			io.KeySuper = false; // ? Is this a problem?
#else
			io.KeySuper = (ev.key.mods.isPressed(ez::KeyMod::System));
#endif
			return true;
		}
		default:
			// Unused event
			return false;
		}
	}

	void Context::newFrame(window::Window& window) {
		assert(ImGui::GetCurrentContext() == ctx);

		backend.newFrame();

		ImGuiIO& io = ImGui::GetIO();
		assert(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer backend. Missing call to renderer _NewFrame() function?");

		glm::vec2 wsize = window.getSize();
		glm::vec2 vsize = window.getViewportSize();
		if (window.isMinimized()) {
			wsize = { 0, 0 };
			vsize = { 0, 0 };
		}

		io.DisplaySize = ImVec2(wsize.x, wsize.y);
		if (wsize.x > 0.f && wsize.y > 0.f) {
			io.DisplayFramebufferScale = ImVec2(vsize.x / wsize.x, vsize.y / wsize.y);
		}
		else {
			io.DisplayFramebufferScale = ImVec2(1.f, 1.f);
		}

		using duration_t = std::chrono::steady_clock::duration;
		using period_t = std::chrono::steady_clock::period;
		using time_t = std::chrono::steady_clock::time_point;

		time_t currentTime = std::chrono::steady_clock::now();
		duration_t delta = currentTime - prevTime;

		if (prevTime == time_t{}) { // Default initialization, first frame
			io.DeltaTime = (1.f / 60.f);
		}
		else {
			io.DeltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(delta).count();
		}
		prevTime = currentTime;

		// Mouse position and buttons
		if (io.WantSetMousePos) {
			window.setCursorPos(glm::ivec2{ (int)io.MousePos.x, (int)io.MousePos.y });
		}
		else {
			io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
		}

		ez::MouseButtons buttons = ez::window::getMouseState();

		io.MouseDown[0] = mousePress[0] || buttons.isPressed(ez::Mouse::Left);
		io.MouseDown[1] = mousePress[1] || buttons.isPressed(ez::Mouse::Right);
		io.MouseDown[2] = mousePress[2] || buttons.isPressed(ez::Mouse::Middle);
		mousePress[0] = false;
		mousePress[1] = false;
		mousePress[2] = false;

		if (window.isKeyboardFocus()) {
			glm::vec2 mpos = window.getCursorPos();
			io.MousePos = ImVec2(mpos.x, mpos.y);
		}

		ez::window::captureMouse(ImGui::IsAnyMouseDown());

		// Mouse Cursors
		if (!(io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)) {
			ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
			if (io.MouseDrawCursor || imgui_cursor == ImGuiMouseCursor_None) {
				// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
				ez::window::Cursor::setVisible(false);
			}
			else {
				// Show OS mouse cursor
				(*cursors)[imgui_cursor].setActive(true);
				ez::window::Cursor::setVisible(true);
			}
		}


		// Game Controllers
		memset(io.NavInputs, 0, sizeof(io.NavInputs));
		if ((io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad) != 0) {
			// Map some buttons and what not, requires game controller setup in SDL, TODO
		}

		ImGui::NewFrame();
	}

	void Context::render() {
		ImGui::Render();
		backend.render();
	}
};

