//
// Created by Alex Tian on 2/22/2023.
//

#ifndef BITBOARDENGINE_USEFUL_H
#define BITBOARDENGINE_USEFUL_H

#include <string>
#include <vector>
#include "constants.h"

template <typename Out>
void split(const std::string &s, char delim, Out result);

std::vector<std::string> split(const std::string &s, char delim);

Piece piece_to_num(char piece);

Square lsb(BITBOARD bitboard);
Square msb(BITBOARD bitboard);

int popcount(BITBOARD bitboard);

Square poplsb(BITBOARD bitboard);

#endif //BITBOARDENGINE_USEFUL_H
