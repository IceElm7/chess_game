/*
 * File:        basePiece.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#include "basePiece.h"

basePiece::basePiece() {
    pieceType = " ";
    //std::cout << "basePiece constructor\n";
}

basePiece::~basePiece() {
    //std::cout << "Destroyed piece\n" << std::endl;
}

void basePiece::draw() {
    // prints the colour and type of piece on board
    if (pieceColour == Black) {
        std::cout << "b";
    }
    else {
        std::cout << "w";
    }
    std::cout << pieceType;
}

void basePiece::setPosition(position pos) {
    this->pos = pos;
}

colour basePiece::getColour() {
    /*
    if (pieceColour == White){
        std::cout<<"w";
    }
    else
        std::cout <<"b";
    */
    return pieceColour;
}

void basePiece::getType() {
    // prints out the piece type
    std::cout<<pieceType;
}

position basePiece::getPosition() {
    std::cout << "x pos = " << pos.xpos
              << "y pos = " << pos.ypos;

    return pos;
}

std::string basePiece::returnType() {
    return pieceType;
}