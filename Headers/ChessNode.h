//
// Created by arti on 29/12/24.
//

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <SFML/Graphics.hpp>

class ChessNode {
private:
    sf::Vector2i position;
    sf::Vector2i size;
    sf::Color color;
    sf::RectangleShape shape;
    sf::Color highlight_color;


public:
    std::vector<ChessNode*> connections;
    int xIndex;
    int yIndex;

    ChessNode(sf::Vector2i pos, sf::Vector2i size, sf::Color color, int xIndex, int yIndex);
    virtual ~ChessNode();
    void addConnection(ChessNode* node);
    void draw(sf::RenderWindow* window);
    void show_connection();
    void toogle_hightlight();
    bool hightlighted;
    void reset();


};
#endif //NODE_H
