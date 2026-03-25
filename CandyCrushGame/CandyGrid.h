#ifndef CANDYGRID_H
#define CANDYGRID_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CandyNode.h"

const int SIZE = 5;

class CandyGrid {
public:
    CandyGrid();
    void displayGrid();
    bool validateMove(int x1, int y1, int x2, int y2);
    void makeMove(int x1, int y1, int x2, int y2);
    int getStarsCollected() const { return starsCollected; }
    int getMovesLeft() const { return movesLeft; }
   

private:
    CandyNode* grid[SIZE][SIZE];
    int starsCollected;
    int movesLeft;

    void initializeStars();
    void initializeColors();
    void detectMatches();
    void refillGrid();
    bool checkValidMoves();
    void decrementMoves() { movesLeft--; }
    bool checkHorizontalMatch(int i, int j);
    bool checkVerticalMatch(int i, int j);
};

#endif
