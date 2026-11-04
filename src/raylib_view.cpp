#include "raylib_view.hpp"
#include "board_layout.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(RAYWHITE);
		// TODO: Draw the board and game status.
		int leftBuffer = BoardLayout::Left;
		int topBuffer = BoardLayout::Top;
		int textBuffer = 20;
		int fontSize = windowW() / 20;

		// Draw Text
		DrawText("Toads & Frogs", leftBuffer, textBuffer, fontSize, BLACK);

		// 1 - 7 cannot be hard coded
		std::string controlsText = "1 - ";
		controlsText += std::to_string(BoardModel::BoardSize);
		controlsText += " = Move Index; R = Restart";
		DrawText(controlsText.c_str(), leftBuffer, textBuffer + fontSize * 1.5, fontSize, BLACK);

		int boxSize = BoardLayout::CellSize;

		Vector2 mp = GetMousePosition();
		std::optional<int> index = BoardLayout::cellAt(mp);
		if (index != std::nullopt) {
			Rectangle r = BoardLayout::cellRect(index.value());
			DrawRectangleRec(r, YELLOW);
		}

		// Draw Box and Numbers
		for (int i = 0; i < model.BoardSize; i++) {
			Rectangle r = BoardLayout::cellRect(i);
			DrawRectangleLinesEx(r, 4, BLACK);
			DrawText(std::to_string(i + 1).c_str(), r.x + r.width / 2 - fontSize/5, r.y + r.height * 1.1, fontSize, BLACK);
		}

		// Draw Frogs and Toads
		int circleRadius = windowW() / 20;
		int y = topBuffer + boxSize / 2;

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

		// Status line
		if (model.state() == BoardModel::GameState::Solved) {
			DrawText("Solved! R to restart.", leftBuffer, 250, fontSize, BLUE);
		}
		else if (model.state() == BoardModel::GameState::Playing) {
			DrawText("Choose a piece to move.", leftBuffer, 250, fontSize, BLACK);
		}
		else {
			DrawText("No moves available! R to restart.", leftBuffer, 250, fontSize, RED);
		}

	}

	int RaylibView::windowW() { return 600; }
	int RaylibView::windowH() { return 300; }
}
