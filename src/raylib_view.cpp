#include "raylib_view.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(RAYWHITE);
		// TODO: Draw the board and game status.
		int leftBuffer = windowW() / 20;
		int topBuffer = windowH() / 10;
		int fontSize = windowW() / 20;

		// Draw Text
		DrawText("Toads & Frogs", leftBuffer, topBuffer, fontSize, BLACK);
		DrawText("1 - 7 = Move Index; R = Restart", leftBuffer, topBuffer + fontSize * 1.5, fontSize, BLACK);

		// Draw Box
		int boxSize = (windowW() - leftBuffer * 2) / model.BoardSize;
		for (int i = 0; i < model.BoardSize; i++) {
			DrawRectangleLines(i * boxSize + leftBuffer, 150, boxSize, boxSize, BLACK);
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
