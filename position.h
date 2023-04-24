//
// Created by Alex Tian on 12/2/2022.
//

#ifndef BITBOARDENGINE_POSITION_H
#define BITBOARDENGINE_POSITION_H

#include <string>
#include "constants.h"

class Position {

public:

    Position() = default;
    BITBOARD all_pieces{};
    BITBOARD our_pieces{};
    BITBOARD opp_pieces{};
    BITBOARD empty_squares{};

    BITBOARD pieces[12]{};

    Piece board[64]{};

    Color side = WHITE;

    int castle_ability_bits = 0;
    Square ep_square = NO_SQUARE;
    HASH_TYPE hash_key = 0;

    BITBOARD get_pieces(Piece piece);
    BITBOARD get_pieces(PieceType piece, Color color);

    BITBOARD get_our_pieces(Color color);
    BITBOARD get_opp_pieces(Color color);

    BITBOARD get_all_pieces();

    BITBOARD get_empty_squares();

    Piece get_piece_standard(Square square);

    Square get_king_pos(Color color);

    void remove_piece(Piece piece, Square square);
    void place_piece(Piece piece, Square square);

    void set_fen(const std::string& fen);

    static void print_bitboard(BITBOARD bitboard);
    void print_board();

};

#endif //BITBOARDENGINE_POSITION_H
