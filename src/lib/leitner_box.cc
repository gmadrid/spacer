#include "leitner_box.h"

#include <algorithm>
#include <chrono>

namespace spacer {

LeitnerBox::LeitnerBox()
    : rnd_(std::chrono::system_clock::now().time_since_epoch().count()) {
  buckets_.resize(total_buckets);
}

Question LeitnerBox::Next(size_t index) const {
  // TODO: validity checks?
  return buckets_[index].back();
}

void LeitnerBox::Shuffle(size_t index) {
  auto &bucket = buckets_[index];
  std::shuffle(bucket.begin(), bucket.end(), rnd_);
}

void LeitnerBox::MoveToFirst(size_t index) {
  if (BucketSize(index) < 1) return;

  auto &from_bucket = buckets_[index];
  auto q = from_bucket.back();
  from_bucket.pop_back();
  buckets_[first_bucket].push_front(q);
}

void LeitnerBox::MoveUp(size_t index) {
  if (BucketSize(index) < 1) return;

  // TODO: have a way to deal with this case.
  if (index == last_bucket) return;

  auto &from_bucket = buckets_[index];
  auto q = from_bucket.back();
  from_bucket.pop_back();
  buckets_[index + 1].push_back(q);
}

}  // namespace spacer
