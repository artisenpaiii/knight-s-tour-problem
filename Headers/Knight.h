//
// Created by arti on 29/12/24.
//

#ifndef HORSE_H
#define HORSE_H

#include <SFML/Graphics.hpp>
#include "ChessBoard.h"
#include <unordered_set>
class Knight {
private:
    sf::Sprite sprite;  
    sf::Texture texture;  
    ChessNode* currentNode;  
    static const int TILE_SIZE = 100;
    std::vector<ChessNode*> path;
    int currentIndexInPath;
    bool running;
    float moveTime;
    float timeElapsed;

public:
    Knight(ChessNode* startNode);
    void move();

    ChessNode* getCurrentNode() const;

    void draw(sf::RenderWindow* window, float deltaTime);
    void calculate_path();
    bool backtrack(ChessNode* currentNode, std::unordered_set<ChessNode*>& visited);
};

#endif //HORSE_H
