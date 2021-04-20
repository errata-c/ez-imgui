#include <ez/imgui/containers/FlexBox.hpp>

namespace ez::imgui {
	std::size_t FlexBox::size() const noexcept {
		return items.size();
	}
	bool FlexBox::empty() const noexcept {
		return items.empty();
	}
	void FlexBox::clear() {
		items.clear();
		totalWidth = 0.0;
	}


}