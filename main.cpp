#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/ChessBoard.h"
#include "Headers/Knight.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    window.setFramerateLimit(60);
    ChessBoard board{};
    ChessNode* start_node = board.getNode(5,5); // CHANGE HERE
    Knight knight{start_node};
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;  

        float deltaTime = clock.restart().asSeconds();

        while (window.pollEvent(event)) {
          
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse = sf::Mouse::getPosition(window);
                    int colIndex = mouse.y / 100;
                    int rowIndex = mouse.x / 100;
                    std::cout << "ROW " << rowIndex << " COL" << colIndex << std::endl;
                    ChessNode* currentNode = board.getNode(colIndex, rowIndex);
                    currentNode->show_connection();
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    board.clearBoard();
                    knight.calculate_path();
                }
            }
        }

        window.clear();  
        board.drawBoard(&window);  
        knight.draw(&window, deltaTime);
        window.display(); 
    }
    return 0;
}
