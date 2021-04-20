#include <ez/imgui/layout/Anchor.hpp>
#include <cmath>

namespace ez::imgui {
	bool Anchor::isXStretch() const noexcept {
		return (stretch.x > 0.f);
	}
	bool Anchor::isYStretch() const noexcept {
		return (stretch.y > 0.f);
	}

	bool Anchor::isXFull() const noexcept {
		return std::abs(stretch.x - 1.f) < 1e-4f;
	}
	bool Anchor::isYFull() const noexcept {
		return std::abs(stretch.y - 1.f) < 1e-4f;
	}

	Rect Anchor::apply(const Rect& area, const glm::vec2& size) const noexcept {
		glm::vec2 invpos = 1.f - position;
		glm::vec2 fsize = size;
		if (stretch.x > 0.f) {
			fsize.x = area.width() * stretch.x;
		}
		if (stretch.y > 0.f) {
			fsize.y = area.height() * stretch.y;
		}

		glm::vec2 space = area.size() - fsize;
		glm::vec2 minp = space * position + area.min;
		glm::vec2 maxp = space * invpos + area.min;

		return Rect{minp, maxp};
	}
}