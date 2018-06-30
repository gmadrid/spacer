#include "leitner_box.h"

#include <algorithm>
#include <chrono>

namespace spacer {

LeitnerBox::LeitnerBox(QuestionSet &&questions, bool shuffle)
    : question_set_(std::move(questions)),
      rnd_(std::chrono::system_clock::now().time_since_epoch().count()) {
  // Create all of the buckets
  buckets_.resize(total_buckets);

  // Then, put all of the questions into bucket 0.
  auto &waiting = buckets_[waiting_bucket];
  for (auto const &q : question_set_) {
    waiting.push_back(&q);
  }
  if (shuffle) {
    std::shuffle(waiting.begin(), waiting.end(), rnd_);
  }
}

Question const *LeitnerBox::Next(size_t index) const {
  // TODO: validity checks?
  return buckets_[index].back();
}

void LeitnerBox::Shuffle(size_t index) {
  auto &bucket = buckets_[index];
  std::shuffle(bucket.begin(), bucket.end(), rnd_);
}

void LeitnerBox::MoveToFirst(size_t index) {
  auto q = buckets_[index].back();
  buckets_[index].pop_back();
  buckets_[first_bucket].push_front(q);
}

void LeitnerBox::MoveUp(size_t index) {
  // TODO: have a way to deal with this case.
  if (index == last_bucket) return;

  auto q = buckets_[index].back();
  buckets_[index].pop_back();
  buckets_[index + 1].push_back(q);
}

}  // namespace spacer
