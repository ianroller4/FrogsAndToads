#include "board_layout.hpp"
#include "board_model.hpp"
#include <cassert> // assert() in cellRect()

namespace FrogToad {
    Rectangle BoardLayout::board() {
        // TODO by You.
        return { Left, Top, BoardModel::BoardSize * CellSize, CellSize }; // Replace with the rectangle covering all cells.
    }

    Rectangle BoardLayout::cellRect(int index) {
        // Assert that the index is valid:
        assert(index >= 0 && index < BoardModel::BoardSize);

        // TODO by You.
        return { Left + index * CellSize, Top, CellSize, CellSize }; // Replace with the calculated rectangle for cell at zero-based position index.
    }

    std::optional<int> BoardLayout::cellAt(Vector2 point) {
        // TODO by You. 
        Rectangle bd = board();
        // First check if mouse is on the board (can exit out earlier if we check this before looping through board)
        if (CheckCollisionPointRec(point, bd)) {
            // On board so loop through board cells
            for (int i = 0; i < BoardModel::BoardSize; i++) {
                Rectangle cell = cellRect(i);
                // Return if mouse is colliding with the current cells rect
                if (CheckCollisionPointRec(point, cell)) {
                    return i;
                }
            }
        }
        else {
            // Return nullopt only when the point is off the board. You can use board() to detect this.
            return std::nullopt;
        }
    }
}