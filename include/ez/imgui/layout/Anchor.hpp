#pragma once 
#include "Rect.hpp"
#include <glm/vec2.hpp>

namespace ez::imgui {
	class _Anchor {
	public:
		// Default anchor is center, no stretch
		constexpr _Anchor() noexcept
			: position(0.5f)
			, stretch(-1.f)
		{}
		constexpr _Anchor(const glm::vec2& p, const glm::vec2& s) noexcept
			: position(p)
			, stretch(s)
		{}

		// Position is the relative positioning of the Item, 0 is left or top, 1 is right or bottom.
		// 0.5 would be centered. Anything out of range [0, 1] would position it outside its containing rect.
		// Given a space to fit inside of, the position calculation takes the remaining area, and divides it up
		// according to this value.
		glm::vec2 position;

		// Values less than or equal to 0 disable stretch, the Item will size to the minimum.
		// Values greater than 0 indicate the relative size of the Item to its containing rect.
		// So a value of 1 will fill the entire region, 0.5 will fill half.
		glm::vec2 stretch;
	};

	// Inheritance so we can have static constexpr implementations of specific anchors
	class Anchor : public _Anchor {
	public:
		static constexpr _Anchor
			Center{},
			CenterLeft{ glm::vec2{0.f, 0.5f}, glm::vec2{-1.f} },
			CenterRight{ glm::vec2{1.f, 0.5f}, glm::vec2{-1.f} },
			CenterTop{ glm::vec2{0.5f, 1.f}, glm::vec2{-1.f} },
			CenterBottom{ glm::vec2{0.5f, 0.f}, glm::vec2{-1.f} },
			TopLeft{ glm::vec2{0.f, 1.f}, glm::vec2{-1.f} },
			TopRight{ glm::vec2{1.f, 1.f}, glm::vec2{-1.f} },
			BottomLeft{ glm::vec2{0.f, 0.f}, glm::vec2{-1.f} },
			BottomRight{ glm::vec2{1.f, 0.f}, glm::vec2{-1.f} },
			Full{ glm::vec2{0.5f}, glm::vec2{1.f} };

		using _Anchor::_Anchor;

		bool isXStretch() const noexcept;
		bool isYStretch() const noexcept;

		bool isXFull() const noexcept;
		bool isYFull() const noexcept;

		// Place item of 'size' into 'region'
		Rect apply(const Rect& region, const glm::vec2& size) const noexcept;

		// Unplace item from 'region', calculate original size
		//glm::vec2 unapply(const Rect& region, const Rect& content) const noexcept;
	};
}