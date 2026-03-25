#ifndef CANDYNODE_H
#define CANDYNODE_H

struct CandyNode {
    char color;
    bool hasStar;
    CandyNode* left;
    CandyNode* right;
    CandyNode* up;
    CandyNode* down;

    CandyNode() : color(' '), hasStar(false), left(nullptr), right(nullptr), up(nullptr), down(nullptr) {}
};

#endif
