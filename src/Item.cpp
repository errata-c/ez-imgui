#include <ez/imgui/Item.hpp>

namespace ez::imgui {
	Item::Item() noexcept
		: minSize(0.f)
	{}
	Rect Item::contentRect(const Rect& region) const noexcept {
		glm::vec2 size = padding.apply(minSize);
		return anchor.apply(region, size);
	}
}