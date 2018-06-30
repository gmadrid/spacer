#include <iostream>

#include "../lib/game.h"

constexpr int WAIT_SECS = 5;

int main(int argc, char *argv[]) {
  spacer::Game game(5);

  game.Loop();
  /*
  TimedInput timed_input(WAIT_SECS);

  std::string input;
  if (timed_input.WaitForInput("Some prompt")) {
    std::cout << "Input: " << timed_input.Input() << std::endl;
  } else {
    std::cout << std::endl << "Timeout!" << std::endl;
  }
  */
  return 0;
}
