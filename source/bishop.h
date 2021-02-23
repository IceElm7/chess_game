/*
 * File:        bishop.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#ifndef PROJECT_BISHOP_H
#define PROJECT_BISHOP_H

#include "basePiece.h"

class bishop : public basePiece {

public:
    bishop(colour colr, position pos);
    virtual ~bishop();
    bool validateMove(position moveToPosition);
};


#endif //PROJECT_BISHOP_H
