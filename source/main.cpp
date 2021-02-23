/*
 * File:        main.cpp
 * Author:      Joseph Amoss
 *              University of Manchester
 * Class:       PHYS30762 Object-Oriented Programming in C++
 * Assignment:  Final Project - Chess
 *
 * Created on April 10, 2020
 */

#include <iostream>
#include "board.h"

// create board object for game to be played on
board mainBoard;

void inputToLowercase(std::string &str);

bool inputCorrect(std::string input1, std::string input2);

position convertToChessNotation(std::string moveStr);

void displayInstructions();

void displayIntro();

int main() {

    // initialize variables for the main game loop
    std::string input1, input2;     // input from users temp variables
    colour turnColor = White;       // colour of current turn
    bool moveSucceed = false;       // can the inputted move be completed or not
    position moveFrom;              // position structure for source location
    position moveTo;                // position structure for target location

    displayIntro();

    while(input1 != "quit") {
        mainBoard.draw();
        //mainBoard.getPiece(position{7,6})->getColour();
        do {
            // display whos turn it is
            if (turnColor == White) {
                std::cout << std::endl << "White's turn" << std::endl;
            } else {
                std::cout << std::endl << "Blacks's turn" << std::endl;
            }

            // input retrieval and validation loop
            do {
                // take source piece
                std::cout << "Please enter where to move from: ";
                std::cin >> input1;

                // make the input lowercase to it can be checked easily
                inputToLowercase(input1);

                // check for quit or help inputs
                if (input1 == "quit") {
                    std::cout << "Thank you for playing" << std::endl;
                    return 0;

                } else if (input1 == "help") {
                    displayInstructions();

                } else {
                    std::cout << "Please enter where to move to: ";
                    std::cin >> input2;

                    inputToLowercase(input2);
                }

                // validate the input; if invalid, loop back to ask again
            } while (input1 == "help" || !inputCorrect(input1, input2));

            // here input must be valid; so convert to the co-ords used to index the board
            moveFrom = convertToChessNotation(input1);
            moveTo = convertToChessNotation(input2);

            // checks the source square has a piece to move
            if(mainBoard.getBoardPiece(moveFrom) == nullptr){
                std::cout << "Move Invalid: Not selected a piece" << std::endl;
                moveSucceed = false;
            }

            // checks the selected piece the right colored piece for the turn
            else if (mainBoard.getBoardPiece(moveFrom)->getColour() != turnColor ) {
                std::cout << "Move Invalid: Wrong color piece selected" << std::endl;
                moveSucceed = false;

            } else {
                // attempts to move chess piece. Validation relating to specific chess
                // piece is is made here
                moveSucceed = mainBoard.movePiece(moveFrom, moveTo);

                // tells user if move failed or not
                if (moveSucceed == false) {
                    std::cout << "Move Invalid" << std::endl;
                } else {
                    std::cout << "Move Completed" << std::endl;
                }
            }

            // if move failed, loop back without redrawing board
        } while (moveSucceed == false);

        // move succeeded so change the colour of player who's turn it is
        if (turnColor == White) {
            turnColor = Black;
        } else if (turnColor == Black) {
            turnColor = White;
        }
    }
}

void inputToLowercase(std::string &str){
    // changes string to all lowercase characters
    // input string by reference

    for(auto iterator=str.begin();iterator<str.end();iterator++){
        *iterator = tolower(*iterator);
    }
}

bool inputCorrect(std::string input1, std::string input2){
    // function only checks that the input is a square on the board

    // check the input is 2 characters as required
    if (input1.size() != 2 || input2.size() != 2) {
        std::cout << "Incorrect input size. Please check that the input is only a letter followed by number" << std::endl;
    }
    else {
        // convert input to Cartesian co-ordinates used to index board
        position moveFrom = convertToChessNotation(input1);
        position moveTo = convertToChessNotation(input2);

        // check if x or y position from the source location is outside the board
        if (moveFrom.xpos < 0 || moveFrom.xpos > 7 || moveFrom.ypos < 0 || moveFrom.ypos > 7) {
            std::cout << "Source location is invalid" << std::endl;
            // check if x or y Position from the target location is outside the board
        } else if (moveTo.xpos < 0 || moveTo.xpos > 7 || moveTo.ypos < 0 || moveTo.ypos > 7) {
            std::cout << "Destination location is invalid" << std::endl;
        } else {
            return true;
        }
    }
    return false;
}

position convertToChessNotation(std::string moveStr) {
    // convert input to Cartesian co-ords
    // position structure is defined in "basePiece.h"

    position movePosition;

    // convert first character (a letter)
    // cast to an int, and subtract 97 to make 0 based
    movePosition.xpos = int (moveStr[0] - 97);
    // convert numeric character to an integer and subtract 1 to make 0 based
    movePosition.ypos = atoi(&moveStr[1]) - 1;

    // return 0 based Cartesian position
    return movePosition;
}

void displayInstructions() {
    // print instructions

    std::cout << "\nInstructions:" << std::endl
         << "To input moves, use standard chess algebraic notation." << std::endl
         << "This consists of a letter (column), followed by a number (row)." << std::endl
         << "The board edges are labeled with this notation for reference." << std::endl
         << "Pieces are designated by w or b for colour, then the piece's first char. (N.B. N = Knight)" << std::endl
         << "At any time you can enter 'quit' to exit or 'help' to receive this information again." << std::endl << std::endl;
}

void displayIntro(){
    // print ascii art introduction

    std::cout << " __      __       .__                                  __          " << std::endl;
    std::cout << "/  \\    /  \\ ____ |  |   ____  ____   _____   ____   _/  |_  ____  " << std::endl;
    std::cout << "\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\  \\   __\\/  _ \\ " << std::endl;
    std::cout << " \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   |  | (  <_> )"<< std::endl;
    std::cout << "  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >  |__|  \\____/ " << std::endl;
    std::cout << "       \\/       \\/          \\/            \\/     \\/                " << std::endl;
    std::cout << "            _________ .__                                                      " << std::endl;
    std::cout << "            \\_   ___ \\|  |__   ____   ______ ______                            " << std::endl;
    std::cout << "            /    \\  \\/|  |  \\_/ __ \\ /  ___//  ___/                            " << std::endl;
    std::cout << "            \\     \\___|   Y  \\  ___/ \\___ \\ \\___ \\                             " << std::endl;
    std::cout << "             \\______  /___|  /\\___  >____  >____  >                            " << std::endl;
    std::cout << "                    \\/     \\/     \\/     \\/     \\/                             " << std::endl << std::endl;
    displayInstructions();
    std::cout << "Press enter to begin" << std::endl;
    std::cin.ignore();
}
