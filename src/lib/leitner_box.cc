#include "leitner_box.h"

namespace spacer {

LeitnerBox::LeitnerBox(QuestionSet &&questions)
    : question_set_(std::move(questions)) {
  // Create all of the buckets
  buckets_.resize(total_buckets);

  // Then, put all of the questions into bucket 0.
  for (auto const &q : question_set_) {
    buckets_[waiting_bucket].push_back(&q);
  }
}

Question const *LeitnerBox::Next(size_t index) const {
  // TODO: validity checks?
  return buckets_[index].back();
}

void LeitnerBox::MoveToFirst(size_t index) {
  if (index == first_bucket) return;

  auto q = buckets_[index].back();
  buckets_[index].pop_back();
  buckets_[first_bucket].push_back(q);
}

void LeitnerBox::MoveUp(size_t index) {
  // TODO: have a way to deal with this case.
  if (index == last_bucket) return;

  auto q = buckets_[index].back();
  buckets_[index].pop_back();
  buckets_[index + 1].push_back(q);
}

}  // namespace spacer
