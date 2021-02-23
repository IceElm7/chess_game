/*
 * File:        pawn.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#ifndef PROJECT_PAWN_H
#define PROJECT_PAWN_H

#include "basePiece.h"

class pawn : public basePiece {
    // initially a pawn can move 2 spaces
    bool doubleJumpPossible;

public:
    pawn(colour colr, position pos);
    virtual ~pawn();

    bool validateMove(position moveToPosition);

};

#endif //PROJECT_PAWN_H

