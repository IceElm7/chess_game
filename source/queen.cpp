/*
 * File:        queen.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#include "queen.h"
#include "board.h"

extern board mainBoard; // board is declared in main.cpp. Extern lets compiler know this


queen::queen(colour colr, position pos) {
    this->pieceType = "Q";
    this->pieceColour = colr;
    this->pos = pos;
    //std::cout << "Queen constructor\n";
}

queen::~queen() {
    //std::cout << "Queen destructor\n";
}

bool queen::validateMove(position moveToPosition) {
    // assume move is allowed; find exceptions
    bool validMove = true;

    // check that if there is a piece at end position; it is of a different colour
    if(mainBoard.getBoardPiece(moveToPosition) != nullptr) {
        if (mainBoard.getBoardPiece(moveToPosition)->getColour() == this->pieceColour) {
            validMove = false;
            std::cout << "Trying to take piece of same colour" << std::endl;
        }
    }

    // COLLISION DETECTION

    // Rook-like movement
    // IDENTICAL TO ROOK CODE
    if (moveToPosition.ypos == pos.ypos || pos.xpos == moveToPosition.xpos) {
        if (moveToPosition.ypos == pos.ypos) {
            // horizontal move

            if (pos.xpos < moveToPosition.xpos) {
                // move right
                for (int i = pos.xpos + 1; i < moveToPosition.xpos; ++i)

                    if (mainBoard.getBoardPiece(position{i, pos.ypos}) != nullptr)
                        validMove = false;

            } else {
                // move left
                for (int i = pos.xpos - 1; i > moveToPosition.xpos; --i)
                    if (mainBoard.getBoardPiece(position{i, pos.ypos}) != nullptr)
                        validMove = false;

            }
        } else if (pos.xpos == moveToPosition.xpos) {
            // vertical move
            if (pos.ypos < moveToPosition.ypos) {
                // move down
                for (int i = pos.ypos + 1; i < moveToPosition.ypos; ++i)

                    if (mainBoard.getBoardPiece(position{pos.xpos, i}) != nullptr)
                        validMove = false;

            } else {
                // move up
                for (int i = pos.ypos - 1; i > moveToPosition.ypos; --i)
                    if (mainBoard.getBoardPiece(position{pos.xpos, i}) != nullptr)
                        //return false;
                        validMove = false;
            }
        } else {
            // Not a valid rook-like move (neither horizontal nor vertical)
            validMove = false;
        }
    }

    else {
        // Bishop-like movement
        // IDENTICAL TO BISHOP CODE
        int diagAway = abs(pos.xpos - moveToPosition.xpos);

        if (pos.xpos + diagAway == moveToPosition.xpos && pos.ypos + diagAway == moveToPosition.ypos) {

            for (int i{1}; i < diagAway; ++i) {
                if (mainBoard.getBoardPiece(position{pos.xpos + i, pos.ypos + i}) != nullptr)
                    validMove = false;
            }

        } else if (pos.xpos - diagAway == moveToPosition.xpos && pos.ypos + diagAway == moveToPosition.ypos) {

            for (int i{1}; i < diagAway; ++i) {
                if (mainBoard.getBoardPiece(position{pos.xpos - i, pos.ypos + i}) != nullptr)
                    validMove = false;
            }

        } else if (pos.xpos + diagAway == moveToPosition.xpos && pos.ypos - diagAway == moveToPosition.ypos) {

            for (int i{1}; i < diagAway; ++i) {
                if (mainBoard.getBoardPiece(position{pos.xpos + i, pos.ypos - i}) != nullptr)
                    validMove = false;
            }

        } else if (pos.xpos - diagAway == moveToPosition.xpos && pos.ypos - diagAway == moveToPosition.ypos) {

            for (int i{1}; i < diagAway; ++i) {
                if (mainBoard.getBoardPiece(position{pos.xpos - i, pos.ypos - i}) != nullptr)
                    validMove = false;
            }
        } else {
            // Not a valid bishop-like move (neither horizontal nor vertical)
            //return false;
            validMove = false;
        }
    }

    return validMove;
}
