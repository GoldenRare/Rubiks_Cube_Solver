#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cstdint>

typedef uint64_t Bitboard; 

enum Color { RED, GREEN, ORANGE, BLUE, YELLOW, WHITE, COLORS };

const constexpr char* COLORS_NOTATION[COLORS] = { "RED", "GREEN", "ORANGE", "BLUE", "YELLOW", "WHITE" };

constexpr int NUMBER_OF_SQUARES = 54;

constexpr Bitboard BOTTOM_FACE = 0b111111111ULL;
constexpr Bitboard TOP_FACE    = BOTTOM_FACE << 9;
constexpr Bitboard LEFT_FACE   = TOP_FACE    << 9;
constexpr Bitboard BACK_FACE   = LEFT_FACE   << 9;
constexpr Bitboard RIGHT_FACE  = BACK_FACE   << 9;
constexpr Bitboard FRONT_FACE  = RIGHT_FACE  << 9;

constexpr uint64_t DE_BRUIJN_SEQUENCE = 0x03F79D71B4CB0A89;
constexpr int DE_BRUIJN_INDEX[64] = {

    0,  1, 48,  2, 57, 49, 28,  3,
   61, 58, 50, 42, 38, 29, 17,  4,
   62, 55, 59, 36, 53, 51, 43, 22,
   45, 39, 33, 30, 24, 18, 12,  5,
   63, 47, 56, 27, 60, 41, 37, 16,
   54, 35, 52, 21, 44, 32, 23, 11,
   46, 26, 40, 15, 34, 20, 31, 10,
   25, 14, 19,  9, 13,  8,  7,  6

};

//Returns the square of the least significant 1 bit 
//using the De Bruijn bitscan algorithm (also sets up for next iteration)
inline int squareOfLS1B(Bitboard* b) {
    Bitboard LS1B = *b & -*b;
    *b &= *b - 1;
    return DE_BRUIJN_INDEX[LS1B * DE_BRUIJN_SEQUENCE >> 58];
}

inline Color operator++(Color& c, int) {
    Color temp = c;
    c = Color((int)c + 1);
    return temp;
}

inline Color operator--(Color& c, int) {
    Color temp = c;
    c = Color((int)c - 1);
    return temp;
}

#endif