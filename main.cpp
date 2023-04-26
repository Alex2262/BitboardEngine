#include <iostream>
#include "position.h"

int main() {
    Position position;
    position.set_fen(START_FEN);
	std::cout << position << std::endl;
}
