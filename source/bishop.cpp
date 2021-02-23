/*
 * File:        bishop.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#include "bishop.h"
#include "board.h"

extern board mainBoard; // board is declared in main.cpp. Extern lets compiler know this

bishop::bishop(colour colr, position pos) {
    this->pieceType = "B";
    this->pieceColour = colr;
    this->pos = pos;
    //std::cout << "Bishop constructor" << std::endl;
}

bishop::~bishop() {
    //std::cout << "Bishop destructor" << std::endl;
}

bool bishop::validateMove(position moveToPosition) {
    // assume move is valid; check for exceptions

    bool validMove = true;

    // check that if there is a piece at end position; it is of a different colour
    if(mainBoard.getBoardPiece(moveToPosition) != nullptr) {
        if (mainBoard.getBoardPiece(moveToPosition)->getColour() == this->pieceColour) {
            validMove = false;
            std::cout << "Trying to take piece of same colour" << std::endl;
        }
    }

    // COLLISION DETECTION
    int diagAway = abs(pos.xpos - moveToPosition.xpos); // x and y distance between current and target position

    if (pos.xpos + diagAway == moveToPosition.xpos && pos.ypos + diagAway == moveToPosition.ypos) {
        // move diagonally up and right
        // std::cout << "move diagonally up and right\n";
        for (int i{1}; i < diagAway; ++i) {
            // checks each square diagonally between the current and target position
            //std::cout << "Checking: x = " << pos.xpos + i << " y = " << pos.ypos +i << std::endl;

            if (mainBoard.getBoardPiece(position{pos.xpos + i, pos.ypos + i}) != nullptr)
                // if a piece is in the way; the move is not valid
                validMove = false;
        }


    }else if (pos.xpos - diagAway == moveToPosition.xpos && pos.ypos + diagAway == moveToPosition.ypos) {
        // move diagonally up and left
        //std::cout << "move diagonally up and left\n";
        for (int i{1}; i < diagAway; ++i) {
            //std::cout << "Checking: x = " << pos.xpos - i << " y = " << pos.ypos +i << std::endl;

            if (mainBoard.getBoardPiece(position{pos.xpos - i, pos.ypos + i}) != nullptr)
                validMove = false;
        }


    }else if (pos.xpos + diagAway == moveToPosition.xpos && pos.ypos - diagAway == moveToPosition.ypos) {
        // move diagonally down and right
        //std::cout << "move diagonally down and right\n";
        for (int i{1}; i < diagAway; ++i) {
            //std::cout << "Checking: x = " << pos.xpos + i << " y = " << pos.ypos -i << std::endl;

            if (mainBoard.getBoardPiece(position{pos.xpos + i, pos.ypos - i}) != nullptr)
                validMove = false;
        }

    }else if (pos.xpos - diagAway == moveToPosition.xpos && pos.ypos - diagAway == moveToPosition.ypos) {
        // move diagonally down and left
        //std::cout << "move diagonally down and left\n";
        for (int i{1}; i < diagAway; ++i) {
            //std::cout << "Checking: x = " << pos.xpos - i << " y = " << pos.ypos - i << std::endl;

            if (mainBoard.getBoardPiece(position{pos.xpos - i, pos.ypos - i}) != nullptr)
                validMove = false;
        }


    }else {
        // not a valid bishop move if not moving on diagonal
        validMove = false;
    }

    return validMove;
}
