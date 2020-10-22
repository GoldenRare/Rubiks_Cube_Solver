#ifndef RUBIKS_CUBE_HPP
#define RUBIKS_CUBE_HPP

#include "utility.hpp"

class RubiksCube {

    public:

        RubiksCube(); //Constructs a default rubik's cube
        void printRubiksCube(); //Gives a visual representation of the current Rubik's cube configuration

    private:

        Bitboard squares[COLORS]; //Most significant of the 9 bits = RED, then GREEN, ORANGE, BLUE (the side faces); YELLOW (the face on top), WHITE (the face on the bottom)
        void initCube(); //Initializes to a default cube
        void printFace(int& i, int offset, const char* face, const char** output); //Helper function to printRubiksCube() which helps in printing a particular face of the cube

};

#endif