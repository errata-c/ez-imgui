#include <ez/imgui/layout/Padding.hpp>
#include <cmath>
#include <glm/common.hpp>

namespace ez::imgui {
	Padding::Padding() noexcept 
		: Padding(0.f, 0.f)
	{}
	Padding::Padding(const glm::vec2& pad) noexcept 
		: Padding(pad.x, pad.y)
	{}
	Padding::Padding(const glm::vec4& pad) noexcept 
		: amount(glm::max(pad, glm::vec4{0.f}))
	{}
	Padding::Padding(float x, float y) noexcept 
		: left(std::max(x, 0.f))
		, right(std::max(x, 0.f))
		, top(std::max(y, 0.f))
		, bottom(std::max(y, 0.f))
	{}
	Padding::Padding(float l, float r, float t, float b) noexcept
		: left(std::max(l, 0.f))
		, right(std::max(r, 0.f))
		, top(std::max(t, 0.f))
		, bottom(std::max(b, 0.f))
	{}

	Padding& Padding::operator=(const glm::vec2& pad) noexcept {
		left = std::max(pad.x, 0.f);
		right = std::max(pad.x, 0.f);
		top = std::max(pad.y, 0.f);
		bottom = std::max(pad.y, 0.f);
		return *this;
	}
	Padding& Padding::operator=(const glm::vec4& pad) noexcept {
		amount = glm::max(pad, glm::vec4{0.f});
		return *this;
	}

	Rect Padding::apply(const Rect& area) const noexcept {
		Rect result = area;
		result.expand(glm::vec2{left, bottom}, glm::vec2{right, top});
		return result;
	}
	Rect Padding::unapply(const Rect& area) const noexcept {
		Rect result = area;
		result.shrink(glm::vec2{ left, bottom }, glm::vec2{ right, top });
		return result;
	}

	glm::vec2 Padding::apply(const glm::vec2& size) const noexcept {
		glm::vec2 result = size;
		result.x += left + right;
		result.y += top + bottom;
		return result;
	}
	glm::vec2 Padding::unapply(const glm::vec2& size) const noexcept {
		glm::vec2 result = size;
		result.x -= left + right;
		result.y -= top + bottom;
		return result;
	}
}