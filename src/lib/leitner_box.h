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

  // Make a box from a set of questions.
  // All questions will be dumped into bucket 0.
  LeitnerBox(QuestionSet&& questions, bool shuffle = true);

  ABSL_MUST_USE_RESULT size_t Size() const { return question_set_.size(); };
  ABSL_MUST_USE_RESULT size_t BucketSize(size_t index) const {
    return buckets_[index].size();
  };

  ABSL_MUST_USE_RESULT Question const* Next(size_t index) const;

  void Shuffle(size_t index);
  void MoveToFirst(size_t index);
  void MoveUp(size_t index);

  /* void Print() const { */
  /*   for (int i = first_bucket; i <= last_bucket; i++) { */
  /*     PrintBucket(i); */
  /*   } */
  /* } */

  /* void PrintBucket(size_t index) const { */
  /*   std::cout << absl::Substitute("Bucket $0", index) << std::endl; */
  /*   for (auto q : buckets_[index]) { */
  /*     std::cout << "  "; */
  /*     print_json(*q); */
  /*   } */
  /* } */

 private:
  // Not copyable
  LeitnerBox(const LeitnerBox&) = delete;
  LeitnerBox(LeitnerBox&&) = delete;
  LeitnerBox& operator=(const LeitnerBox&) = delete;
  LeitnerBox& operator=(LeitnerBox&&) = delete;

  // Add 1 since buckets are 1-indexed.
  static constexpr size_t total_buckets = last_bucket + 1;

  using Bucket = std::deque<Question const*>;
  using Buckets = std::deque<Bucket>;

  // We own the QuestionSet, so we can put ptrs into it in the buckets.
  // Since it's const, the ptrs will never change.
  QuestionSet const question_set_;
  Buckets buckets_;
  std::default_random_engine rnd_;
};

void to_json(json& j, LeitnerBox const& q);
void from_json(json const& j, LeitnerBox& p);

}  // namespace spacer

#endif  // SPACER_LIB_LEITNER_BOX_H
