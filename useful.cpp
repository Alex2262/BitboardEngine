//
// Created by Alex Tian on 2/22/2023.
//

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "constants.h"


template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


Piece piece_to_num(char piece) {

    auto it = std::find(std::begin(PIECE_MATCHER), std::end(PIECE_MATCHER), piece);
    return static_cast<Piece>(it - std::begin(PIECE_MATCHER));
}


// Compiler specific functions, taken from Stockfish https://github.com/official-stockfish/Stockfish
#if defined(__GNUC__) // GCC, Clang, ICC

Square lsb(BITBOARD bitboard)
{
    assert(bitboard);
    return static_cast<Square>(__builtin_ctzll(bitboard));
}

Square msb(BITBOARD bitboard)
{
    assert(bitboard);
    return static_cast<Square>(63 ^ __builtin_clzll(bitboard));
}

#elif defined(_MSC_VER) // MSVC

#ifdef _WIN64 // MSVC, WIN64
#include <intrin.h>
Square lsb(U64 b)
{
    unsigned long idx;
    _BitScanForward64(&idx, b);
    return (Square)idx;
}

Square msb(U64 b)
{
    unsigned long idx;
    _BitScanReverse64(&idx, b);
    return (Square)idx;
}

#else // MSVC, WIN32
#include <intrin.h>
Square lsb(U64 b)
{
    unsigned long idx;

    if (b & 0xffffffff)
    {
        _BitScanForward(&idx, int32_t(b));
        return Square(idx);
    }
    else
    {
        _BitScanForward(&idx, int32_t(b >> 32));
        return Square(idx + 32);
    }
}

Square msb(U64 b)
{
    unsigned long idx;

    if (b >> 32)
    {
        _BitScanReverse(&idx, int32_t(b >> 32));
        return Square(idx + 32);
    }
    else
    {
        _BitScanReverse(&idx, int32_t(b));
        return Square(idx);
    }
}

#endif

#else // Compiler is neither GCC nor MSVC compatible

#error "Compiler not supported."

#endif

int popcount(BITBOARD bitboard)
{
#if defined(_MSC_VER) || defined(__INTEL_COMPILER)

    return (uint8_t)_mm_popcnt_u64(mask);

#else // Assumed gcc or compatible compiler

    return __builtin_popcountll(bitboard);

#endif
}

Square poplsb(BITBOARD &bitboard)
{
    Square s = lsb(bitboard);
    bitboard &= bitboard - 1; // compiler optimizes this to _blsr_u64
    return static_cast<Square>(s);
}

