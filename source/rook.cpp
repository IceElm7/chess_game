/*
 * File:        rook.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#include "rook.h"
#include "board.h"

extern board mainBoard; // board is declared in main.cpp. Extern lets compiler know this

rook::rook(colour colr, position pos) {
    this->pieceType = "R";
    this->pieceColour = colr;
    this->pos = pos;
    //std::cout << "Rook constructor" << std::endl;

}

rook::~rook() {
    //std::cout << "Rook destructor" << std::endl;
}

bool rook::validateMove(position moveToPosition) {
    // assume move is allowed; fin exceptions
    bool validMove = true;

    // FOR TESTING
    /*
    std::cout   << "moveFrom x = " << pos.xpos
                << "\nmoveFrom y = " << pos.ypos
                << "\nmoveTo x = " <<   moveToPosition.xpos
                << "\nmoveTo y = " <<   moveToPosition.ypos
                << "\n";
    */

    // check that if there is a piece at end position; it is of a different colour
    if(mainBoard.getBoardPiece(moveToPosition) != nullptr) {
        if (mainBoard.getBoardPiece(moveToPosition)->getColour() == this->pieceColour) {
            validMove = false;
            std::cout << "Trying to take piece of same colour" << std::endl;
        }
    }

    // COLLISION DETECTION

    if (moveToPosition.ypos == pos.ypos) {
        // horizontal move

        if (pos.xpos < moveToPosition.xpos) {
            // move right
            for (int i = pos.xpos + 1; i < moveToPosition.xpos; ++i)

                if (mainBoard.getBoardPiece(position{i,pos.ypos}) != nullptr)
                    validMove = false;

        } else {
            // move left
            for (int i = pos.xpos - 1; i > moveToPosition.xpos; --i)
                if (mainBoard.getBoardPiece(position{i,pos.ypos}) != nullptr)
                    validMove = false;

        }
    } else if (pos.xpos == moveToPosition.xpos) {
        // vertical move
        if (pos.ypos < moveToPosition.ypos) {
            // move down
            for (int i = pos.ypos + 1; i < moveToPosition.ypos; ++i)

                if (mainBoard.getBoardPiece(position{pos.xpos,i}) != nullptr)

                    // return false;
                    validMove = false;

        } else {
            // move up
            for (int i = pos.ypos - 1; i > moveToPosition.ypos; --i)
                if (mainBoard.getBoardPiece(position{pos.xpos,i}) != nullptr)
                    //return false;
                    validMove = false;
        }
    } else {
        // Not a valid rook move (neither horizontal nor vertical)
        validMove = false;
    }

    return validMove;
}

