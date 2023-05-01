#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lib/doctests.h"
#include "../position.h"

int factorial(int number) {
	return number <= 1 ? number : factorial(number - 1) * number;
}
TEST_SUITE_BEGIN("board-rep");

TEST_CASE("testing the factorial function") {
	Position p;
	p.get_piece_attacks<WHITE, PAWN>(a1);
}

TEST_SUITE_END();