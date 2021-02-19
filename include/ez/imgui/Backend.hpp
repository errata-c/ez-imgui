#pragma once

struct ImDrawData;

namespace ez::imgui {
	struct BackendData;

	class Backend {
	public:
		Backend();
		~Backend();

		bool init();
		void shutdown();
		void newFrame();
		void render();
	private:
		BackendData* _data;
	};
};