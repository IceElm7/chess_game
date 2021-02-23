/*
 * File:        pawn.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#include "pawn.h"
#include "board.h"

extern board mainBoard; // board is declared in Main. Extern lets compiler know this

pawn::pawn(colour colr, position pos) {
    this->pieceType = "P";
    this->pieceColour = colr;
    this->pos = pos;
    this->doubleJumpPossible = true;
    //std::cout << "Pawn constructor" << std::endl;
}

pawn::~pawn() {
    //std::cout << "Pawn destructor" << std::endl;
}

bool pawn::validateMove(position moveToPosition){
    // assume move is invalid; check for exceptions
    // not many moves a pawn can make
    bool validMove = false;
    int allowableMoveY = 1;
    int allowableMoveYDouble = 2;

    // if black piece, moves down the board
    if(pieceColour == Black){
        allowableMoveY = -1;
        allowableMoveYDouble = -2;
    }

    // one square forward to empty square
    // can always make this move if there is nothing in front
    if(moveToPosition.ypos == (pos.ypos + allowableMoveY) && moveToPosition.xpos == pos.xpos && mainBoard.getBoardPiece(moveToPosition) ==
                                                                                                      nullptr){
        validMove = true;
        // after this; double jump is always false; assigns this each time
        doubleJumpPossible = false;
    }

    // two squares forward. Only on pawns first turn
    else if( doubleJumpPossible == true && moveToPosition.ypos == (pos.ypos + allowableMoveYDouble) && moveToPosition.xpos == pos.xpos && mainBoard.getBoardPiece(moveToPosition) ==
                                                                                                                                                  nullptr){
        validMove = true;
        doubleJumpPossible = false;
    }

    // diagonal left or right by one square. Must be another piece there to attack.
    else if (moveToPosition.ypos == pos.ypos + allowableMoveY && (moveToPosition.xpos == pos.xpos - 1 || moveToPosition.xpos == pos.xpos + 1) ) {

        // check if there is a piece in the diagonal position, if so, is it an opposite color
        if (mainBoard.getBoardPiece(moveToPosition) != nullptr && (mainBoard.getBoardPiece(moveToPosition)->getColour() != this->pieceColour) )  {
            validMove = true;
        }
    }

    return validMove;




}
