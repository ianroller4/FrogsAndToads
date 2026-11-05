#include "raylib_controller.hpp"
#include "raylib.h"
#include "board_layout.hpp"
#include <iostream>

namespace FrogToad {
	void RaylibController::handleInput(BoardModel& model) {
		// TODO (student): Implement non-blocking keyboard input.

		const int key = GetKeyPressed();
		int keyIndex = 0;

		// Check for R key
		if (key == KEY_R) {
			model.reset();
			return;
		}

		// Ensures index is mapped properly as for example KEY_ONE = 49 so minus KEY_ZERO gets 1 
		// and then minus 1 again gets the proper array index
		keyIndex = key - KEY_ZERO - 1;

		// Check if key index is in range of board size
		if (keyIndex >= 0 && keyIndex < BoardModel::BoardSize) {
			model.tryMove(keyIndex);
		} // Check for mouse input
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			std::optional<int> index = BoardLayout::cellAt(GetMousePosition());
			// Check if mouse on valid cell
			if (index != std::nullopt) {
				// Try move if index is not null
				model.tryMove(index.value());
			}
		}
		return;
	}
}
