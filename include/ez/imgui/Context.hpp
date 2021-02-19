#pragma once
#include <cinttypes>
#include <string>
#include <chrono>
#include <ez/input/InputEvent.hpp>

#include "Backend.hpp"

struct ImGuiContext;

namespace ez::window {
	class Window;
}

namespace ez::imgui {
		
	// Associate with a window.
	// That way we can use clipboard and update mouse and other things.
	class Context {
	public:
		Context(window::Window & window);
		~Context();

		void makeActive();
		bool isActive() const;

		bool processEvent(const ez::InputEvent& ev);

		void newFrame(window::Window & window);

		void render();
	private:
		ImGuiContext* ctx;
		std::chrono::steady_clock::time_point prevTime;
		bool mousePress[3];
		std::string clipboard;

		Backend backend;
	};
};