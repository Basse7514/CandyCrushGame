#include "CandyGrid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

CandyGrid::CandyGrid() {
    starsCollected = 0;
    movesLeft = 20;
    srand(static_cast<unsigned>(time(nullptr))); // Seed for random number generation

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = new CandyNode();

    initializeStars();
    initializeColors();
}

void CandyGrid::initializeStars() {
    int starsPlaced = 0;
    while (starsPlaced < 5) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (!grid[x][y]->hasStar) {
            grid[x][y]->hasStar = true;
            starsPlaced++;
        }
    }
}

void CandyGrid::initializeColors() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!grid[i][j]->hasStar) {
                char colors[] = { 'R', 'G', 'B' };
                grid[i][j]->color = colors[rand() % 3];
            }
        }
    }

    if (!checkValidMoves()) {
        initializeColors();
    }
}

bool CandyGrid::validateMove(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE ||
        x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE ||
        !(abs(x1 - x2) + abs(y1 - y2) == 1)) // Check if adjacent
    {
        return false;
    }

    std::swap(grid[x1][y1]->color, grid[x2][y2]->color);
    bool hasMatch = checkHorizontalMatch(x1, y1) || checkVerticalMatch(x1, y1) ||
        checkHorizontalMatch(x2, y2) || checkVerticalMatch(x2, y2);
    std::swap(grid[x1][y1]->color, grid[x2][y2]->color);
    return hasMatch;
}

void CandyGrid::makeMove(int x1, int y1, int x2, int y2) {
    std::swap(grid[x1][y1]->color, grid[x2][y2]->color);
    detectMatches();
    decrementMoves();
    refillGrid();
}

void CandyGrid::detectMatches() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (checkHorizontalMatch(i, j)) continue;
            if (checkVerticalMatch(i, j)) continue;
        }
    }
}

bool CandyGrid::checkHorizontalMatch(int i, int j) {
    int hCount = 1;
    while (j + hCount < SIZE && grid[i][j]->color == grid[i][j + hCount]->color) {
        hCount++;
    }
    if (hCount >= 3) {
        for (int k = 0; k < hCount; k++) {
            if (grid[i][j + k]->hasStar) {
                starsCollected++;
                grid[i][j + k]->hasStar = false;
            }
            grid[i][j + k]->color = ' ';
        }
        return true;
    }
    return false;
}

bool CandyGrid::checkVerticalMatch(int i, int j) {
    int vCount = 1;
    while (i + vCount < SIZE && grid[i][j]->color == grid[i + vCount][j]->color) {
        vCount++;
    }
    if (vCount >= 3) {
        for (int k = 0; k < vCount; k++) {
            if (grid[i + k][j]->hasStar) {
                starsCollected++;
                grid[i + k][j]->hasStar = false;
            }
            grid[i + k][j]->color = ' ';
        }
        return true;
    }
    return false;
}

void CandyGrid::refillGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]->color == ' ') {
                char colors[] = { 'R', 'G', 'B' };
                grid[i][j]->color = colors[rand() % 3];
            }
        }
    }
}

bool CandyGrid::checkValidMoves() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((j < SIZE - 1 && validateMove(i, j, i, j + 1)) ||
                (i < SIZE - 1 && validateMove(i, j, i + 1, j))) {
                return true;
            }
        }
    }
    return false;
}



void CandyGrid::displayGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]->hasStar) {
                std::cout << "[" << grid[i][j]->color << "*] ";
            }
            else {
                std::cout << "[" << grid[i][j]->color << "] ";
            }
        }
        std::cout << std::endl;
    }
}
