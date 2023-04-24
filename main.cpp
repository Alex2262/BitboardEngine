#include <iostream>
#include "position.h"

int main() {
    Position position;
    position.set_fen(START_FEN);
    position.print_board();
}
