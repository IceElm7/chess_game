/*
 * File:        board.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#include "board.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include <iostream>     // for std::cout

// initialised a vector of length 64 (representing 8x8 grid)
board::board() : gameBoard(64) {
    //std::cout << "Default board" << std::endl;
    initializePieces();
}

board::~board() {}

// draw 8x8 chess board with pieces (if present)
void board::draw() {
    for (int row = 7; row >= 0; row--) {

        // draws horizontal row dividers
        std::cout << "   ";
        for (int col = 0; col < 8; col++) {
            std::cout << "-----";
        }
        std::cout << "-" << std::endl;

        // draws vertical row divider and chess piece (if present)
        std::cout << row + 1 << "  "; // numbers on side of board
        for (int col = 0; col < 8; col++) {
            std::cout << "| ";

            basePiece *currPiece(gameBoard[row * 8 + col].getPiece());

            if (currPiece != nullptr) {
                // if a piece is present; calls piece draw function (colourPIECE)
                currPiece->draw();
            } else {
                // ensures board is lined up; needs 2 spaces
                std::cout << "  ";
            }
            std::cout << " ";
        }

        // draws divider for end of a row
        std::cout << "|" << std::endl;

    }

    // draws horizontal divider for last row
    std::cout << "   ";
    for (int col = 0; col < 8; col++) {
        std::cout << "-----";
    }
    std::cout << "-" << std::endl;

    // draw letters at base of board
    std::cout << "   ";
    for (int col = 0; col < 8; col++) {
        // alphabet from char ASCII characters
        std::cout << "  " << (char) (col + 97) << "  ";
    }
    std::cout << std::endl << std::endl;
}

void board::initializePieces() {
    // put pieces onto board at beginning of game

    // pawns
    for (int col = 0; col < 8; col++) {
        position blackPawnPos = {col, 6};
        gameBoard[8*blackPawnPos.ypos + blackPawnPos.xpos].setPiece(new pawn(Black, blackPawnPos));

        position whitePawnPos = {col, 1};
        gameBoard[8*whitePawnPos.ypos + blackPawnPos.xpos].setPiece(new pawn(White, whitePawnPos));

        // NOTE REGARDING ISSUE WITH SMART POINTERS; WANTED TO COME BACK AND FIX BUT DIDN'T HAVE THE TIME
        // no viable conversion from pawn* to std::shared_ptr<basePiece>
        // as had to make the pointers used in basePiece shared so they don't go out of scope, raw pointers couldn't be used to make the
        // pieces object (SetPieces takes smart pointer), i.e. pawns, so had to initialise them specifically as unique_pointers
    }

    // rooks
    // piece is a pointer to a basePiece
    position blackRookPos = {0, 7};
    gameBoard[blackRookPos.xpos + 8*blackRookPos.ypos].setPiece(new rook(Black, blackRookPos));

    position blackRookPos2 = {7, 7};
    gameBoard[blackRookPos2.xpos + 8*blackRookPos2.ypos].setPiece( new rook(Black, blackRookPos2));

    position whiteRookPos = {0, 0};
    gameBoard[whiteRookPos.xpos + 8*whiteRookPos.ypos].setPiece(new rook(White, whiteRookPos));

    position whiteRookPos2 = {7, 0};
    gameBoard[whiteRookPos2.xpos + 8*whiteRookPos2.ypos].setPiece(new rook(White, whiteRookPos2));

    // knights
    position blackKnightPos = {1, 7};
    gameBoard[blackKnightPos.xpos + 8*blackKnightPos.ypos].setPiece(new knight(Black, blackKnightPos));

    position blackKnightPos2 = {6, 7};
    gameBoard[blackKnightPos2.xpos + 8*blackKnightPos2.ypos].setPiece(new knight(Black, blackKnightPos2));

    position whiteKnightPos = {1, 0};
    gameBoard[whiteKnightPos.xpos + 8*whiteKnightPos.ypos].setPiece(new knight(White, whiteKnightPos));

    position whiteKnightPos2 = {6, 0};
    gameBoard[whiteKnightPos2.xpos + 8*whiteKnightPos2.ypos].setPiece( new knight(White, whiteKnightPos2));

    // bishops
    position blackBishopPos = {2, 7};
    gameBoard[blackBishopPos.xpos + 8*blackBishopPos.ypos].setPiece(new bishop(Black, blackBishopPos));

    position blackBishopPos2 = {5, 7};
    gameBoard[blackBishopPos2.xpos + 8*blackBishopPos2.ypos].setPiece( new bishop(Black, blackBishopPos2));

    position whiteBishopPos = {2, 0};
    gameBoard[whiteBishopPos.xpos + 8*whiteBishopPos.ypos].setPiece(new bishop(White, whiteBishopPos));

    position whiteBishopPos2 = {5, 0};
    gameBoard[whiteBishopPos2.xpos + 8*whiteBishopPos2.ypos].setPiece(new bishop(White, whiteBishopPos2));

    // queens
    position blackQueenPos = {3, 7};
    gameBoard[blackQueenPos.xpos + 8*blackQueenPos.ypos].setPiece(new queen(Black, blackQueenPos));

    position whiteQueenPos = {3, 0};
    gameBoard[whiteQueenPos.xpos + 8*whiteQueenPos.ypos].setPiece( new queen(White, whiteQueenPos));

    // kings
    position blackKingPos = {4, 7};
    gameBoard[blackKingPos.xpos + 8*blackKingPos.ypos].setPiece(new king(Black, blackKingPos));

    position whiteKingPos = {4, 0};
    gameBoard[whiteKingPos.xpos + 8*whiteKingPos.ypos].setPiece( new king(White, whiteKingPos));


    // pieces used for testing validate move functionality

    //position BlackRookPosTest = {2,4};
    //gameBoard[BlackRookPosTest.xpos + 8*BlackRookPosTest.ypos].setPiece(new rook(Black, BlackRookPosTest));

    //position whiteBishopPosTest = {4, 2};
    //gameBoard[whiteBishopPosTest.xpos + 8*whiteBishopPosTest.ypos].setPiece(new bishop(White, whiteBishopPosTest));

    //position PawnPosTest = {1, 6};
    //gameBoard[PawnPosTest.xpos + 8*PawnPosTest.ypos].setPiece(new pawn(White, PawnPosTest));

}

bool board::movePiece(position fromPos, position toPos) {
    // MAIN FUNCTION FOR GAME FUNCTIONALITY
    // checks an inputted move is valid for the specific piece
    // if it is; sets the piece at the new position
    // deletes piece taken and promotes pawn to queen if it reaches the opposite end

    bool moveCompleted = false;

    // identify the piece user wants to move
   basePiece *origPiece = gameBoard[8*fromPos.ypos + fromPos.xpos].getPiece();

   // checks move to and from aren't the same square
   if(fromPos.ypos == toPos.ypos && fromPos.xpos == toPos.xpos){
        moveCompleted = false;
    }

    // check if users move can be performed
    // validate move must be true
    else if (origPiece != nullptr && origPiece->validateMove(toPos)){

        // make the move
        // if the user takes a piece with their move; that piece is taken (deleted) first
        if(gameBoard[8*toPos.ypos + toPos.xpos].getPiece() != nullptr){
            gameBoard[8*toPos.ypos + toPos.xpos].takePiece();

        }

       // sets the piece to the new position and clears the piece at the old position
        origPiece->setPosition(toPos);
        gameBoard[8*toPos.ypos + toPos.xpos].setPiece(origPiece);
        gameBoard[8*fromPos.ypos + fromPos.xpos].clearPiece();

        moveCompleted = true;
    }

    // promotes pawn to queen if it reaches the opposite side
    if(moveCompleted == true && origPiece->returnType() == "P" && ((origPiece->getColour() == White && toPos.ypos == 7))){
        gameBoard[8*toPos.ypos + toPos.xpos].takePiece();
        gameBoard[8*toPos.ypos + toPos.xpos].setPiece(new queen(White,toPos));
    }
    if(moveCompleted == true && origPiece->returnType() == "P" && ((origPiece->getColour() == Black && toPos.ypos == 0))){
        gameBoard[8*toPos.ypos + toPos.xpos].takePiece();
        gameBoard[8*toPos.ypos + toPos.xpos].setPiece(new queen(Black,toPos));
    }

    // return move status
    return moveCompleted;


}

basePiece* board::getBoardPiece(position piecePos){
    // find square piece is on; get piece (pointer to a piece)

    return gameBoard[piecePos.xpos + 8*piecePos.ypos].getPiece();
}