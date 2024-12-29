//
// Created by arti on 29/12/24.
//
#include "ChessBoard.h"
#include "ChessNode.h"
#include <stdexcept>

static const int knightMoves[8][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};

ChessBoard::ChessBoard() : board(SIZE, std::vector<ChessNode*>(SIZE, nullptr)) {
    initializeBoard();
    connectNodes();
}
ChessBoard::~ChessBoard() {
    // Clean up all nodes
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            delete board[i][j];
        }
    }
}
void ChessBoard::initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // Alternate colors based on row and column indices
            sf::Color squareColor = ((i + j) % 2 == 0) ? sf::Color::White : sf::Color::Black;

            // Create a ChessNode with position, size, and color
            board[i][j] = new ChessNode(sf::Vector2i(j * TILE_SIZE, i * TILE_SIZE),
                                        sf::Vector2i(TILE_SIZE, TILE_SIZE),
                                        squareColor, j, i);
        }
    }
}

void ChessBoard::connectNodes() {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            ChessNode* currentNode = board[row][col];

            for (const auto& move: knightMoves) {
                int newRow = row + move[0];
                int newCol = col + move[1];

                if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                    currentNode->addConnection(board[newRow][newCol]);
                }
            }
        }
    }
}

ChessNode* ChessBoard::getNode(int row, int col) const {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        throw std::out_of_range("Invalid board position");
    }
    return board[row][col];
}

void ChessBoard::drawBoard(sf::RenderWindow *window) const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j]->draw(window);
        }
    }
}

void ChessBoard::clearBoard(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j]->reset();
        }
    }
}
