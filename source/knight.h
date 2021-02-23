/*
 * File:        knight.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#ifndef PROJECT_KNIGHT_H
#define PROJECT_KNIGHT_H

#include "basePiece.h"

class knight : public basePiece {

public:
    knight(colour colr, position pos);
    virtual ~knight();
    bool validateMove(position moveToPosition);

};

#endif //PROJECT_KNIGHT_H
