#ifndef SPACER_LIB_GAME_H
#define SPACER_LIB_GAME_H

#include "absl/base/attributes.h"

#include "leitner_box.h"
#include "mnemonica.h"
#include "schedule.h"
#include "timed_input.h"

namespace spacer {

class Game {
 public:
  Game(time_t timeout)
      : schedule_(7), leitner_box_(mnemonica()), timed_input_(timeout) {
    leitner_box_.Shuffle(LeitnerBox::waiting_bucket);
  }

  void Loop();

 private:
  // No copy/move
  Game(const Game &) = delete;
  Game(Game &&) = delete;
  Game &operator=(const Game &) = delete;
  Game &operator=(Game &&) = delete;

  Schedule schedule_;
  LeitnerBox leitner_box_;
  TimedInput timed_input_;
};

}  // namespace spacer

#endif  // SPACER_LIB_GAME_H
