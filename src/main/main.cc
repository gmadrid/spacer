#include <iostream>

#include "../lib/timed_input.h"

using spacer::TimedInput;

constexpr int WAIT_SECS = 5;

int main(int argc, char *argv[]) {
  TimedInput timed_input(WAIT_SECS);

  std::string input;
  if (timed_input.WaitForInput("Some prompt")) {
    std::cout << "Input: " << timed_input.Input() << std::endl;
  } else {
    std::cout << std::endl << "Timeout!" << std::endl;
  }

  return 0;
}
