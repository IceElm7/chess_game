/*
 * File:        queen.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 12, 2020
 */

#ifndef PROJECT_QUEEN_H
#define PROJECT_QUEEN_H

#include "basePiece.h"

class queen : public basePiece {

public:
    queen(colour colr, position pos);
    virtual ~queen();
    bool validateMove(position moveToPosition);

};


#endif //PROJECT_QUEEN_H
