#include <iostream>
#include "rubiksCube.hpp"
#include "utility.hpp"

RubiksCube::RubiksCube() {

    initCube();

}

void RubiksCube::printRubiksCube() {

    const char* output[NUMBER_OF_SQUARES];
    Bitboard findSquares;
    for (Color c = RED; c <= WHITE; c++) {
        findSquares = squares[c];
        while (findSquares)
            output[squareOfLS1B(&findSquares)] = COLORS_NOTATION[c];
    }

    int i = NUMBER_OF_SQUARES - 1;
    printFace(i, 1, "FRONT FACE", output);
    printFace(i, 2, "RIGHT FACE", output);
    printFace(i, 3, "BACK FACE", output);
    printFace(i, 4, "LEFT FACE", output);
    printFace(i, 5, "TOP FACE", output);
    printFace(i, 6, "BOTTOM FACE", output);

}

void RubiksCube::printFace(int& i, int offset, const char* face, const char** output) {

    int count = 0;
    for (; i >= NUMBER_OF_SQUARES - 9 * offset; i--) {
        if (++count == 1) std::cout << face << ":" << std::endl << std::endl; 
        std::cout << output[i] << "  ";
        if (!(count % 3)) std::cout << std::endl << std::endl;
    }
}

void RubiksCube::initCube() {

    Bitboard init = 0b111111111ULL;
    for (Color c = WHITE; c >= RED; c--) {
        squares[c] = init;
        init <<= 9;
    }
}