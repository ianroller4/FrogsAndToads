#include "raylib_controller.hpp"
#include "raylib.h"

namespace FrogToad {
	void RaylibController::handleInput(BoardModel& model) {
		// TODO (student): Implement non-blocking keyboard input.

		// Support 1 - 7 and r
		if (IsKeyDown(KEY_ONE)) {
			model.tryMove(0);
		} 
		else if (IsKeyDown(KEY_TWO)) {
			model.tryMove(1);
		}
		else if (IsKeyDown(KEY_THREE)) {
			model.tryMove(2);
		}
		else if (IsKeyDown(KEY_FOUR)) {
			model.tryMove(3);
		}
		else if (IsKeyDown(KEY_FIVE)) {
			model.tryMove(4);
		}
		else if (IsKeyDown(KEY_SIX)) {
			model.tryMove(5);
		}
		else if (IsKeyDown(KEY_SEVEN)) {
			model.tryMove(6);
		} 
		else if (IsKeyDown(KEY_R)) {
			model.reset();
		} 
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

		}
		return;
	}
}
