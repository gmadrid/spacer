#include <iostream>

#include "../lib/game.h"

constexpr int WAIT_SECS = 5;

int main(int argc, char *argv[]) {
  spacer::Game game(5);
  game.Loop();

  return 0;
}
