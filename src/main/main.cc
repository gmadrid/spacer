#include <iostream>

#include <tclap/CmdLine.h>

#include "../lib/game.h"

constexpr auto VERSION = "0.0.1";

constexpr size_t NUM_NEW_QUESTIONS = 7;
constexpr time_t WAIT_SECS = 10;

int main(int argc, char *argv[]) {
  try {
    TCLAP::CmdLine cmd("Spaced repetition trainer.", ' ', VERSION);
    TCLAP::ValueArg<time_t> secs("s", "secs",
                                 "Seconds before question is unanswered.",
                                 false, WAIT_SECS, "positive number", cmd);
    TCLAP::ValueArg<size_t> toAdd(
        "a", "add", "Number of questions to add when bucket 1 is empty.", false,
        NUM_NEW_QUESTIONS, "positive number", cmd);

    cmd.parse(argc, argv);

    spacer::Game game(secs.getValue());
    game.Loop(toAdd.getValue());

  } catch (TCLAP::ArgException &e) {
    std::cerr << "error: " << e.error() << " for arg " << e.argId()
              << std::endl;
  }

  return 0;
}
