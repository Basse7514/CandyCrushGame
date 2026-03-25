#include "CandyGrid.h"
#include <iostream>

int main() {
    CandyGrid game;

    while (game.getMovesLeft() > 0 && game.getStarsCollected() < 5) {
        game.displayGrid();
        std::cout << "Stars Collected: " << game.getStarsCollected() << std::endl;
        std::cout << "Moves Left: " << game.getMovesLeft() << std::endl;

        int x1, y1, x2, y2;
        std::cout << "Enter the coordinates of the candies to swap (x1 y1 x2 y2): ";
        std::cin >> x1 >> y1 >> x2 >> y2;

        if (game.validateMove(x1, y1, x2, y2)) {
            game.makeMove(x1, y1, x2, y2);
        }
        else {
            std::cout << "Invalid move! Please try again." << std::endl;
        }
    }

    if (game.getStarsCollected() == 5) {
        std::cout << "You won the game!" << std::endl;
    }
    else {
        std::cout << "Game over!" << std::endl;
    }

    return 0;
}
