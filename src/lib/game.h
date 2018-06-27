#ifndef SPACER_LIB_GAME_H
#define SPACER_LIB_GAME_H

#include "leitner_box.h"
#include "mnemonica.h"
#include "schedule.h"

namespace spacer {

class Game {
 public:
  Game() : schedule_(7), leitner_box_(mnemonica()) {}

  // No copy/move
  Game(const Game &) = delete;
  Game(Game &&) = delete;
  Game &operator=(const Game &) = delete;
  Game &operator=(Game &&) = delete;

 private:
  Schedule schedule_;
  LeitnerBox leitner_box_;
};

}  // namespace spacer

#endif  // SPACER_LIB_GAME_H