/*
 * File:        king.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#include "king.h"
#include "board.h"

extern board mainBoard; // board is declared in main.cpp. Extern lets compiler know this


king::king(colour colr, position pos) {
    this->pieceType = "K";
    this->pieceColour = colr;
    this->pos = pos;
    //std::cout << "King constructor" << std::endl;
}

king::~king() {
    //std::cout << "King destructor" << std::endl;
}

bool king::validateMove(position moveToPosition) {
    // assume move is invalid; check for exceptions
    bool validMove = true;
    // king only has 8 possible moves; listed here
    std::vector<int> movesX {-1 , 0, +1, +1, +1, 0, -1, -1};
    std::vector<int> movesY = {+1, +1, +1, 0, -1, -1, -1, 0};

    // check that if there is a piece at end position; it is of a different colour
    if(mainBoard.getBoardPiece(moveToPosition) != nullptr) {
        if (mainBoard.getBoardPiece(moveToPosition)->getColour() == this->pieceColour) {
            validMove = false;
            std::cout << "Trying to take piece of same colour" << std::endl;
        }
    }

    int count{0};
    // runs through and tests all possible move combinations
    for(int i{0}; i < movesX.size();i++){
        // if valid move was found, stops testing
        if(count == 1){break;}

        //std::cout << count << std::endl;
        //std::cout << "Testing: x = " << pos.xpos + movesX[i] << "  y = " << pos.ypos + movesY[i] << std::endl;

        // if current position + an allowable move gives final position; allowable
        if(pos.xpos + movesX[i] == moveToPosition.xpos && pos.ypos + movesY[i] == moveToPosition.ypos){
            count++;
        }

    }
    if(count != 1){
        validMove = false;
    }
    return validMove;
}
