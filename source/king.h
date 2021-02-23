/*
 * File:        king.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#ifndef PROJECT_KING_H
#define PROJECT_KING_H

#include "basePiece.h"

class king : public basePiece {

public:
    king(colour colr, position pos);
    virtual ~king();
    bool validateMove(position moveToPosition);

};

#endif //PROJECT_KING_H
