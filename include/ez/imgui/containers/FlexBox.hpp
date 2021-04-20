#pragma
#include <vector>
#include <ez/imgui/layout/Enumerators.hpp>
#include <ez/imgui/layout/Rect.hpp>

// Layout based on CSS FlexBox

// Either horizontal or vertical.
// Forward or reverse direction.
// Justify content: start, end, center, space between, space around, space even
// Align content: start, end, center, stretch, baseline

// Allow for padding, and for resizing by dragging handles.

/*
Elements added should have flags that specify if they will expand, and by how much.
*/
namespace ez::imgui {
	class Item;

	class FlexBox {
	public:
		FlexBox();

		void push(const Item & item);

		std::size_t size() const noexcept;
		bool empty() const noexcept;
		void clear();

		bool begin(const Rect& region);
		void next();
		void end();

		Direction direction;
		Orientation orientation;
		Align align;
		Justify justify;
		
	private:
		double totalWidth;

		struct IData {
			// Per item width.
			float width;


		};

		std::vector<IData> items;
	};
}