#include "raylib_view.hpp"
#include "board_layout.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(SKYBLUE);
		// TODO: Draw the board and game status.
		int leftBuffer = BoardLayout::Left; // Gap for x drawing
		int topBuffer = BoardLayout::Top; // Gap for y drawing
		int textBuffer = 20; // Gap for text from top
		int fontSize = windowW() / 20; // Font size

		// Draw Game Title
		DrawText("Toads & Frogs", leftBuffer, textBuffer, fontSize, BLACK);

		// Build string for controls based on board size
		std::string controlsText = "1 - ";
		controlsText += std::to_string(BoardModel::BoardSize);
		controlsText += " = Move Index; R = Restart";

		// Draw Game Controls
		DrawText(controlsText.c_str(), leftBuffer, textBuffer + fontSize * 1.5, fontSize, BLACK);

		// Get cell size for rectangles
		int boxSize = BoardLayout::CellSize;

		// Draw Background Box
		DrawRectangle(leftBuffer, topBuffer, boxSize * model.BoardSize, boxSize, SKYBLUE);

		// Determine if mouse is above a cell
		Vector2 mp = GetMousePosition();
		std::optional<int> index = BoardLayout::cellAt(mp);
		if (index != std::nullopt) {
			Rectangle r = BoardLayout::cellRect(index.value());
			DrawRectangleRec(r, ORANGE);
		}

		// Draw Box and Numbers
		for (int i = 0; i < model.BoardSize; i++) {
			Rectangle r = BoardLayout::cellRect(i);
			DrawRectangleLinesEx(r, 4, BLACK);
			DrawText(std::to_string(i + 1).c_str(), r.x + r.width / 2 - fontSize/5, r.y + r.height * 1.1, fontSize, BLACK);
		}

		// Frog, toads, and lilypad settings
		int lilyPadRadius = boxSize * 0.75;
		int circleRadius = boxSize / 4;
		int y = topBuffer + boxSize / 2;

		// Draw Frogs and Toads
		for (int i = 0; i < model.BoardSize; i++) {
			int x = i * boxSize + boxSize / 2 + leftBuffer;
			DrawCircle(x, y, lilyPadRadius / 2, DARKGREEN);
			if (model.cellAt(i) == BoardModel::Cell::Frog) {
				// Frog Body
				DrawCircle(x - circleRadius / 2, y, circleRadius * 0.75, GREEN);
				// Frog Eye 1
				DrawCircle(x + circleRadius * 0.25, y + circleRadius * 0.5, circleRadius * 0.5, GREEN);
				DrawCircle(x + circleRadius * 0.25, y + circleRadius * 0.5, circleRadius * 0.25, WHITE);
				DrawCircle(x + circleRadius * 0.25, y + circleRadius * 0.5, circleRadius * 0.1, BLACK);
				// Frog Eye 2
				DrawCircle(x + circleRadius * 0.25, y - circleRadius * 0.5, circleRadius * 0.5, GREEN);
				DrawCircle(x + circleRadius * 0.25, y - circleRadius * 0.5, circleRadius * 0.25, WHITE);
				DrawCircle(x + circleRadius * 0.25, y - circleRadius * 0.5, circleRadius * 0.1, BLACK);
			}
			else if (model.cellAt(i) == BoardModel::Cell::Toad) {
				// Toad Body
				DrawCircle(x + circleRadius / 2, y, circleRadius * 0.75, BROWN);
				// Toad Eye 1
				DrawCircle(x - circleRadius * 0.25, y + circleRadius * 0.5, circleRadius * 0.5, BROWN);
				DrawCircle(x - circleRadius * 0.25, y + circleRadius * 0.5, circleRadius * 0.25, WHITE);
				DrawCircle(x - circleRadius * 0.25, y + circleRadius * 0.5, circleRadius * 0.1, BLACK);
				// Toad Eye 2
				DrawCircle(x - circleRadius * 0.25, y - circleRadius * 0.5, circleRadius * 0.5, BROWN);
				DrawCircle(x - circleRadius * 0.25, y - circleRadius * 0.5, circleRadius * 0.25, WHITE);
				DrawCircle(x - circleRadius * 0.25, y - circleRadius * 0.5, circleRadius * 0.1, BLACK);
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
