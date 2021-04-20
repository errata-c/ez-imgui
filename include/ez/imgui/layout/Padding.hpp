#pragma once 
#include "Rect.hpp"
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

namespace ez::imgui {
	class Padding {
	public:
		Padding(const Padding&) noexcept = default;
		~Padding() = default;
		Padding& operator=(const Padding&) noexcept = default;

		Padding() noexcept;
		Padding(const glm::vec2& pad) noexcept;
		Padding(const glm::vec4& pad) noexcept;
		Padding(float x, float y) noexcept;
		Padding(float left, float right, float top, float bottom) noexcept;

		Padding& operator=(const glm::vec2& pad) noexcept;
		Padding& operator=(const glm::vec4& pad) noexcept;

		Rect apply(const Rect & area) const noexcept;
		Rect unapply(const Rect& area) const noexcept;

		glm::vec2 apply(const glm::vec2& size) const noexcept;
		glm::vec2 unapply(const glm::vec2& size) const noexcept;

		// The actual padding values, they are in the order: left right top bottom.
		union {
			glm::vec4 amount;
			struct {
				float left, right, top, bottom;
			};
		};
	};
}