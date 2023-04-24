//
// Created by Alex Tian on 12/2/2022.
//

#include <stdexcept>
#include <iostream>
#include <cassert>
#include <bitset>
#include "position.h"
#include "useful.h"

BITBOARD Position::get_pieces(Piece piece) {
    return pieces[piece];
}

BITBOARD Position::get_pieces(PieceType piece, Color color) {
    return pieces[piece + color * 6];
}

BITBOARD Position::get_our_pieces(Color color) {
    return get_pieces(PAWN, color) | get_pieces(KNIGHT, color) | get_pieces(BISHOP, color) |
           get_pieces(ROOK, color) | get_pieces(QUEEN, color) | get_pieces(KING, color);
}

BITBOARD Position::get_opp_pieces(Color color) {
    return get_our_pieces(static_cast<Color>(~color));
}

BITBOARD Position::get_all_pieces() {
    return get_our_pieces(WHITE) | get_our_pieces(BLACK);
}

BITBOARD Position::get_empty_squares() {
    return ~get_all_pieces();
}

Piece Position::get_piece_standard(Square square) {
    return board[square];
}

Square Position::get_king_pos(Color color) {
    return lsb(get_pieces(KING, color));
}

void Position::remove_piece(Piece piece, Square square) {
    pieces[piece] &= ~(1ULL << square);
    board[square] = EMPTY;
}

void Position::place_piece(Piece piece, Square square) {
    pieces[piece] |= (1ULL << square);
    board[square] = piece;
}

void Position::set_fen(const std::string& fen_string) {

    std::vector<std::string> fen_tokens = split(fen_string, ' ');

    if (fen_tokens.size() < 4) {
        throw std::invalid_argument( "Fen is incorrect" );
    }

    const std::string position = fen_tokens[0];
    const std::string player = fen_tokens[1];
    const std::string castling = fen_tokens[2];
    const std::string en_passant = fen_tokens[3];

    const std::string half_move_clock = fen_tokens.size() > 4 ? fen_tokens[4] : "0";
    const std::string full_move_counter = fen_tokens.size() > 4 ? fen_tokens[5] : "1";

    side = (player == "w") ? WHITE : BLACK;

    for (int piece = WHITE_PAWN; piece != EMPTY; piece++) {
        pieces[piece] = 0ULL;
    }

    auto pos = static_cast<Square>(56);

    // Parsing the main 8x8 board part while adding appropriate padding
    for (char c : position) {
        if (c == '/' ) {
            pos = static_cast<Square>(pos - 16);
        } else if (std::isdigit(c)) {

            for (int empty_amt = 0; empty_amt < c - '0'; empty_amt++) {
                board[pos] = EMPTY;
                pos = static_cast<Square>(pos + 1);
            }

        }
        else if (std::isalpha(c)) {

            Piece piece = piece_to_num(c);
            place_piece(piece, pos);

            pos = static_cast<Square>(pos + 1);

        }
    }

    castle_ability_bits = 0;
    for (char c : castling) {

        if (c == 'K') castle_ability_bits |= 1;
        else if (c == 'Q') castle_ability_bits |= 2;
        else if (c == 'k') castle_ability_bits |= 4;
        else if (c == 'q') castle_ability_bits |= 8;

    }

    if (en_passant.size() > 1) {
        auto square = static_cast<Square>((8 - (en_passant[1] - '0')) * 8 + en_passant[0] - 'a');
        ep_square = square;
    }
    else {
        ep_square = NO_SQUARE;
    }
}

void Position::print_bitboard(BITBOARD bitboard)
{
    std::bitset<64> b(bitboard);
    std::string str_bitset = b.to_string();
    for (int i = 0; i < 64; i += 8)
    {
        std::string x = str_bitset.substr(i, 8);
        reverse(x.begin(), x.end());
        std::cout << x << std::endl;
    }
    std::cout << '\n' << std::endl;
}

void Position::print_board() {
    std::string new_board;

    auto pos = static_cast<Square>(56);
    for (int i = 0; i < 64; i++) {
        if (i != 0 && i % 8 == 0) {
            new_board += '\n';
            pos = static_cast<Square>(pos - 16);
        }

        Piece piece = board[pos];
        pos = static_cast<Square>(pos + 1);

        if (piece == EMPTY) {
            new_board += ". ";
            continue;
        }

        //assert((pieces[piece] & (1ULL << MAILBOX_TO_STANDARD[pos]) >> MAILBOX_TO_STANDARD[pos]) == 1);

        new_board += PIECE_MATCHER[piece];
        new_board += ' ';

    }

    std::cout << new_board << std::endl << std::endl;
    std::cout << "side: " << side << " ep: " << ep_square << " castle: " << castle_ability_bits
              << " hash: " << hash_key << std::endl << std::endl;

    for (int piece = WHITE_PAWN; piece < EMPTY; piece++) {
        std::cout << "Piece: " << piece << " bitboard: \n";
        print_bitboard(pieces[piece]);
    }
}