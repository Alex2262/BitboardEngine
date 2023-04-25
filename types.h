#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

enum Color : int {
	WHITE,
	BLACK,
};

constexpr Color operator~(Color c) {
	return Color(c ^ BLACK);
}

constexpr uint32_t NPIECES = 15;
enum Piece : uint32_t {
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
};

constexpr uint32_t NSQUARES = 15;
enum Square : uint32_t {
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

enum PieceType : uint32_t {
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum MoveType : uint8_t {
	MOVE_TYPE_NORMAL,
	MOVE_TYPE_EP,
	MOVE_TYPE_CAPTURE,
	MOVE_TYPE_CASTLE,
	MOVE_TYPE_PROMOTION
};


using PLY_TYPE = uint32_t;
using HASH_TYPE = uint64_t;
using BITBOARD = uint64_t;
#endif // TYPES_H