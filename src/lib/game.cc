#include "game.h"

#include "absl/strings/str_cat.h"

namespace spacer {

using std::cout;
using std::endl;

void Game::Loop() {
  // 1. Get current level from schedule.
  // 2. If bucket in LB has contents.
  //    a. Pop question
  //    b. ask question
  //    c. if correct, move up
  //       else move to first
  //  else
  //    a. pop current
  // 3. Loop
  while (true) {
    if (leitner_box_.BucketSize(LeitnerBox::first_bucket) == 0 &&
        leitner_box_.BucketSize(LeitnerBox::first_bucket + 1) == 0) {
      int new_qs = 5;
      cout << "Adding " << new_qs << " new questions." << endl;
      while (new_qs-- &&
             leitner_box_.BucketSize(LeitnerBox::waiting_bucket) > 0) {
        leitner_box_.MoveToFirst(LeitnerBox::waiting_bucket);
      }
    }

    // BUG! This will infinite loop if the box is completely empty!
    auto bucket_index = schedule_.Current();
    if (leitner_box_.BucketSize(bucket_index) == 0) {
      schedule_.PopCurrent();
      continue;
    }

    auto q = leitner_box_.Next(bucket_index);
    auto answered = timed_input_.WaitForInput(q->QuestionString());
    if (!answered) {
      cout << absl::StrCat("TIMES UP! ", q->QuestionString(), " ==> ",
                           q->Answer())
           << endl;
      leitner_box_.MoveToFirst(bucket_index);
    } else {
      if (q->Match(timed_input_.Input())) {
        leitner_box_.MoveUp(bucket_index);
      } else {
        cout << absl::StrCat("Nope! ", q->QuestionString(), " ==> ",
                             q->Answer())
             << endl;
        leitner_box_.MoveToFirst(bucket_index);
      }
    }
  }
}

}  // namespace spacer
