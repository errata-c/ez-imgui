#pragma once
#include "layout/Rect.hpp"
#include "layout/Anchor.hpp"
#include "layout/Padding.hpp"

// define an item class to represent the abstract gui item.
// It will store an expected size, and allow customization of a number of attributes.
// However, we don't want it to be too heavy, so make sure not to add too many 'features'

/*
Anchor: The placement of the item inside the space given to it. This includes stretch.
Area: The expected space the item will take up. Word wrap complicates this...
 
Items shouldn't care about expanding, that should be handled by their container.
This means stretch is the only thing that will actually matter to an item. This also simplifies the work
containers need to do substantially.

padding? margin? borders?
Padding is the area between the borders and the actual content.
Margin is the area around the borders.
Borders are typically the frame around the content. Often they are a different color, to accentuate the content.

Borders and padding seem important, but they can be made by simply encapsulating an item inside another.

*/

namespace ez::imgui {
	class Item {
	public:
		Item() noexcept;

		// Calculate content rect from the placement region.
		Rect contentRect(const Rect & region) const noexcept;

		Anchor anchor;
		Padding padding;
		glm::vec2 minSize;
	};
}