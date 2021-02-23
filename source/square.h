/*
 * File:        square.h
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#ifndef PROJECT_SQUARE_H
#define PROJECT_SQUARE_H

#include "basePiece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <memory>

class square {
protected:
    // each square has a pointer to a chess piece
    basePiece* chessPiece;

public:
    square();
    virtual ~square();

    basePiece* getPiece();
    void setPiece(basePiece *piece);
    void clearPiece();
    void takePiece();

};


#endif //PROJECT_SQUARE_H
