#include <SFML/Graphics.hpp>
#include "ChessNode.h"


ChessNode::ChessNode(sf::Vector2i pos, sf::Vector2i size, sf::Color color, int xIndex, int yIndex)
    : position{pos}, size{size}, color{color}, highlight_color{sf::Color::Green}, xIndex {xIndex}, yIndex {yIndex} {
    hightlighted = false;
    shape.setSize(sf::Vector2f(size.x, size.y));  
    shape.setFillColor(color);                      
    shape.setPosition(sf::Vector2f(position.x, position.y));  
}

ChessNode::~ChessNode() {}

void ChessNode::addConnection(ChessNode* node) {
    connections.push_back(node);  
}

void ChessNode::draw(sf::RenderWindow* window) {
    window->draw(shape); 
}

void ChessNode::show_connection() {
    for (ChessNode* node : connections) {
        node->toogle_hightlight();
    }
}

void ChessNode::toogle_hightlight() {
    hightlighted = !hightlighted;

    if (hightlighted) {
        shape.setFillColor(highlight_color);
    } else {
        shape.setFillColor(color);
    }
}

void ChessNode::reset(){
    hightlighted = false;
    shape.setFillColor(color);
}

