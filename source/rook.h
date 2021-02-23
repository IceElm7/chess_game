/*
 * File:        rook.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#ifndef PROJECT_ROOK_H
#define PROJECT_ROOK_H

#include "basePiece.h"

class rook : public basePiece {

public:
    rook(colour colr, position pos);
    virtual ~rook();
    bool validateMove(position moveToPosition);

};

#endif //PROJECT_ROOK_H
