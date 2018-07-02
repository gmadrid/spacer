#ifndef SPACER_LIB_LEITNER_BOX_H
#define SPACER_LIB_LEITNER_BOX_H

#include <deque>
#include <random>

#include "absl/base/attributes.h"

#include "json_helpers.h"
#include "question.h"

namespace spacer {

class LeitnerBox {
 public:
  static constexpr size_t first_bucket = 1;
  static constexpr size_t last_bucket = 7;
  static constexpr size_t waiting_bucket = 0;

  // An empty LeitnerBox.
  LeitnerBox();

  LeitnerBox(const LeitnerBox&) = default;
  LeitnerBox(LeitnerBox&&) = default;
  LeitnerBox& operator=(const LeitnerBox&) = default;
  LeitnerBox& operator=(LeitnerBox&&) = default;

  // Add all questions (in order) to the waiting bucket.
  template <typename T>
  void AddQuestions(const T& questions);

  ABSL_MUST_USE_RESULT size_t Size() const { return num_questions_; };
  ABSL_MUST_USE_RESULT size_t BucketSize(size_t index) const {
    return buckets_[index].size();
  };

  ABSL_MUST_USE_RESULT Question Next(size_t index) const;

  void Shuffle(size_t index);
  void MoveToFirst(size_t index);
  void MoveUp(size_t index);

 private:
  // Add 1 since buckets are 1-indexed.
  static constexpr size_t total_buckets = last_bucket + 1;

  using Bucket = std::deque<Question>;
  using Buckets = std::deque<Bucket>;

  size_t num_questions_ = 0;
  Buckets buckets_;
  std::default_random_engine rnd_;
};

template <typename T>
void LeitnerBox::AddQuestions(const T& questions) {
  std::copy(begin(questions), end(questions), std::back_inserter(buckets_[0]));
  num_questions_ += questions.size();
}

void to_json(json& j, LeitnerBox const& q);
void from_json(json const& j, LeitnerBox& p);

}  // namespace spacer

#endif  // SPACER_LIB_LEITNER_BOX_H
