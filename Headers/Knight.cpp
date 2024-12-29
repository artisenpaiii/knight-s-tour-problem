//
// Created by arti on 29/12/24.
//
#include "Knight.h"
#include <iostream>
#include "ChessBoard.h"
#include <queue>
#include <unordered_set>

Knight::Knight(ChessNode* startNode) :     currentNode{startNode}, currentIndexInPath{0}, running{false}, timeElapsed{0}, moveTime{0.2} {
    if (!texture.loadFromFile("../hourse.png")) {
        throw std::runtime_error("Failed to load knight texture");
    }
    sprite.setTexture(texture);
    // Get the texture size
    sf::Vector2u textureSize = texture.getSize();
    float scaleX = 100.0f / textureSize.x;
    float scaleY = 100.0f / textureSize.y;

    sprite.setScale(scaleX, scaleY);

    sprite.setPosition(sf::Vector2f(50 + currentNode->xIndex * TILE_SIZE - sprite.getGlobalBounds().width / 2,
                                     50 + currentNode->yIndex * TILE_SIZE - sprite.getGlobalBounds().height / 2));

}

ChessNode* Knight::getCurrentNode() const {
    return currentNode;
}

void Knight::draw(sf::RenderWindow* window, float deltaTime) {
    if (running) {
        timeElapsed += deltaTime; 

  
        if (timeElapsed >= moveTime) {
            move();
            timeElapsed = 0.0f;  
        }
    }
    window->draw(sprite); 
}

void Knight::calculate_path() {
    currentIndexInPath = 0;
    std::unordered_set<ChessNode*> visited;  
    path.clear();  
    visited.insert(currentNode);
    path.push_back(currentNode);  


    if (backtrack(currentNode, visited)) {
        running = true;
    } else {
        std::cout << "No solution found." << std::endl;
    }
}


bool Knight::backtrack(ChessNode* currentNode, std::unordered_set<ChessNode*>& visited) {
   
    std::cout << "Visiting: (" << currentNode->xIndex << ", " << currentNode->yIndex << ")"
              << " | Visited nodes: " << visited.size() << std::endl;

    
    if (visited.size() == 64) {
        std::cout << "Path found! All squares visited." << std::endl;
        return true;  
    }

    int min_moves = 9;  
    ChessNode* newNode = nullptr;


    std::vector<ChessNode*> validMoves;
    for (auto& connection : currentNode->connections) {

        if (visited.find(connection) == visited.end()) {
            validMoves.push_back(connection);
        }
    }

    std::sort(validMoves.begin(), validMoves.end(), [](ChessNode* a, ChessNode* b) {
        return a->connections.size() < b->connections.size();
    });

    for (auto& move : validMoves) {

            visited.insert(move);  
            path.push_back(move);  

           
            if (backtrack(move, visited)) {
                this->currentNode = path.back();
                return true;

            }
            visited.erase(move);  
            path.pop_back();  
            std::cout << "Backtracking from: (" << move->xIndex << ", " << move->yIndex << ")" << std::endl;
    }

    
    std::cout << "No valid moves found from (" << currentNode->xIndex << ", " << currentNode->yIndex << ")." << std::endl;
    return false;  
}

void Knight::move() {
    if (currentIndexInPath < path.size()) {
        ChessNode* node = path[currentIndexInPath++];
        sprite.setPosition(sf::Vector2f(50 + node->xIndex * TILE_SIZE - sprite.getGlobalBounds().width / 2,
                                         50 + node->yIndex * TILE_SIZE - sprite.getGlobalBounds().height / 2));
        node->toogle_hightlight();
    } else {
        running = false;
        std::cout << "Knight has completed the path!" << std::endl;
    }

}


