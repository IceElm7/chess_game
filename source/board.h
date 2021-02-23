/*
 * File:        board.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H

#include "square.h"
#include <vector>

class board {
protected:
    // 64 'squares' make up board; stored in a vector. Access with multiplication of rows and columns
    std::vector<square> gameBoard;

    // places all the pieces on the board in the first instance
    void initializePieces();

public:
    board();
    ~board();

    void draw();
    bool movePiece(position fromPos, position toPos);
    basePiece* getBoardPiece(position piecePos);
};

#endif //PROJECT_BOARD_H



