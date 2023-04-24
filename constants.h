//
// Created by Alex Tian on 12/2/2022.
//

#ifndef BITBOARDENGINE_CONSTANTS_H
#define BITBOARDENGINE_CONSTANTS_H

#include <cstdint>


#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - "
#define KIWIPETE_FEN "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - "

enum Color : int {
    WHITE,
    BLACK,
    NO_COLOR
};

enum Piece : int {
    WHITE_PAWN,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_ROOK,
    WHITE_QUEEN,
    WHITE_KING,
    BLACK_PAWN,
    BLACK_KNIGHT,
    BLACK_BISHOP,
    BLACK_ROOK,
    BLACK_QUEEN,
    BLACK_KING,
    EMPTY,
    PADDING
};

enum Square : int {
    a1, b1, c1, d1, e1, f1, g1, h1,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a8, b8, c8, d8, e8, f8, g8, h8,
    NO_SQUARE
};

enum PieceType : int {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum MoveType : int {
    MOVE_TYPE_NORMAL,
    MOVE_TYPE_EP,
    MOVE_TYPE_CASTLE,
    MOVE_TYPE_PROMOTION
};


typedef uint8_t PLY_TYPE;
typedef int SCORE_TYPE;
typedef uint64_t HASH_TYPE;
typedef uint64_t BITBOARD;


constexpr char PIECE_MATCHER[12] = {'P', 'N', 'B', 'R', 'Q', 'K', 'p', 'n', 'b', 'r', 'q', 'k'};

#endif //BITBOARDENGINE_CONSTANTS_H
