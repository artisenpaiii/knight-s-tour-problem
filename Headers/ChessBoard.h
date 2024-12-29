#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessNode.h"
#include <vector>

class ChessBoard {
private:
    static const int SIZE = 8;
    const int TILE_SIZE = 100;  

    std::vector<std::vector<ChessNode*>> board;

public:
    ChessBoard();
    ~ChessBoard();

    void initializeBoard();
    void connectNodes();
    ChessNode* getNode(int row, int col) const;
    void drawBoard(sf::RenderWindow *window) const;
    void clearBoard();
};

#endif // CHESSBOARD_H
