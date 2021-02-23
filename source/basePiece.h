/*
 * File:        basePiece.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#ifndef PROJECT_BASEPIECE_H
#define PROJECT_BASEPIECE_H

#include <iostream>

// enum defined for colour of pieces
enum colour {
    Black,
    White
};

// struct defined to hold the Cartesian position (0-based) of pieces
typedef struct {
    int xpos;
    int ypos;
} position;

class basePiece {
public:
    basePiece();
    virtual ~basePiece();

    void draw();
    void setPosition(position pos);
    position getPosition();
    colour getColour();
    std::string returnType();
    void getType();
    virtual bool validateMove(position moveToPosition) = 0;

protected:
    std::string pieceType;
    colour pieceColour;
    position pos;

};

#endif //PROJECT_BASEPIECE_H
