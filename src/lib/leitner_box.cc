#include "leitner_box.h"

#include <algorithm>
#include <chrono>

namespace spacer {

LeitnerBox::LeitnerBox()
    : rnd_(std::chrono::system_clock::now().time_since_epoch().count()) {
  buckets_.resize(total_buckets);
}

bool LeitnerBox::operator==(LeitnerBox const &rhs) const {
  return num_questions_ == rhs.num_questions_ && buckets_ == rhs.buckets_;
}

std::ostream &operator<<(std::ostream &stream, const LeitnerBox &lb) {
  stream << json(lb);
  return stream;
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

constexpr auto buckets_jkey = "buckets";
constexpr auto num_questions_jkey = "num_questions";

void to_json(json &j, LeitnerBox const &lb) {
  j[buckets_jkey] = lb.buckets_;
  j[num_questions_jkey] = lb.num_questions_;
}

void from_json(json const &j, LeitnerBox &lb) {
  size_t num_questions = j[num_questions_jkey];
  LeitnerBox::Buckets buckets = j[buckets_jkey];

  lb.num_questions_ = num_questions;
  lb.buckets_ = buckets;
}

}  // namespace spacer
