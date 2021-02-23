/*
 * File:        square.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#include "square.h"

square::square() {
    chessPiece = nullptr;
}

square::~square() {
}

basePiece* square::getPiece() {
    return chessPiece;
}
void square::setPiece(basePiece *piece){
    // RELIC OF TRYING TO USE SMART POINTER
    // chessPiece = std::move(piece);

    // sets the pointer (chess piece) on this square to the basePiece passed
    this->chessPiece = piece;
}
void square::clearPiece() {
    //delete(chessPiece);

    this->chessPiece = nullptr;

}

void square::takePiece(){
    delete(chessPiece);


}

