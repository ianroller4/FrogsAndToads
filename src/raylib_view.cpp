#include "raylib_view.hpp"
#include "board_layout.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(RAYWHITE);
		// TODO: Draw the board and game status.
		int leftBuffer = BoardLayout::Left;
		int topBuffer = BoardLayout::Top;
		int fontSize = windowW() / 20;

		

		// Draw Text
		DrawText("Toads & Frogs", leftBuffer, topBuffer / 2, fontSize, BLACK);

		// 1 - 7 cannot be hard coded
		DrawText("1 - 7 = Move Index; R = Restart", leftBuffer, topBuffer / 2 + fontSize * 1.5, fontSize, BLACK);

		int boxSize = BoardLayout::CellSize;

		Vector2 mp = GetMousePosition();
		std::optional<int> index = BoardLayout::cellAt(mp);
		if (index != std::nullopt) {
			DrawRectangle(index.value() * boxSize + leftBuffer, topBuffer, boxSize, boxSize, YELLOW);
		}

		// Draw Box
		for (int i = 0; i < model.BoardSize; i++) {
			DrawRectangleLines(i * boxSize + leftBuffer, topBuffer, boxSize, boxSize, BLACK);
		}

		// Draw Frogs and Toads
		int circleRadius = windowW() / 20;
		int y = 150 + boxSize / 2;

		for (int i = 0; i < model.BoardSize; i++) {
			if (model.cellAt(i) == BoardModel::Cell::Frog) {
				int x = i * boxSize + boxSize / 2 + leftBuffer;
				DrawCircle(x, y, circleRadius, RED);
			}
			else if (model.cellAt(i) == BoardModel::Cell::Toad) {
				int x = i * boxSize + boxSize / 2 + leftBuffer;
				DrawCircle(x, y, circleRadius, BLUE);
			}
		}
	}

	int RaylibView::windowW() { return 600; }
	int RaylibView::windowH() { return 300; }
}
