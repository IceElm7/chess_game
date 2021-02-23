/*
 * File:        knight.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#include "knight.h"
#include "board.h"

extern board mainBoard; // board is declared in main.cpp. Extern lets compiler know this

knight::knight(colour colr, position pos) {
    this->pieceType = "N";
    this->pieceColour = colr;
    this->pos = pos;
    //std::cout << "Knight constructor" << std::endl;

}

knight::~knight() {
    //std::cout << "Knight destructor" << std::endl;

}

bool knight::validateMove(position moveToPosition) {
    // move allowed, unless violated
    bool validMove = true;

    // list of allowable moves
    std::vector<int> movesX {-2 , -2, -1, -1, +1, +1, +2, +2};
    std::vector<int> movesY = {+1, -1, +2, -2, +2, -2, +1, -1};

    // check that if there is a piece at end position; it is of a different colour
    if(mainBoard.getBoardPiece(moveToPosition) != nullptr) {
        if (mainBoard.getBoardPiece(moveToPosition)->getColour() == this->pieceColour) {
            validMove = false;
            std::cout << "Trying to take piece of same colour" << std::endl;
        }
    }

    // same check as king.cpp; tests all allowable moves and if current position + allowable moves gives
    // end position -> allowed

    int count{0};
    for(int i{0}; i < movesX.size();i++){
        // if valid move was found, stops testing
        if(count == 1){break;}

        //std::cout << count << std::endl;
        //std::cout << "Testing: x = " << pos.xpos + movesX[i] << "  y = " << pos.ypos + movesY[i] << std::endl;
        if(pos.xpos + movesX[i] == moveToPosition.xpos && pos.ypos + movesY[i] == moveToPosition.ypos){
            count++;
        }

    }
    if(count != 1){
        validMove = false;
    }

    return validMove;
}