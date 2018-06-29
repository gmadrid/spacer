#ifndef SPACER_LIB_LEITNER_BOX_H
#define SPACER_LIB_LEITNER_BOX_H

#include <vector>

#include "absl/base/attributes.h"

#include "question.h"

namespace spacer {

class LeitnerBox {
 public:
  static constexpr size_t first_bucket = 1;
  static constexpr size_t last_bucket = 7;
  static constexpr size_t waiting_bucket = 0;

  // Make a box from a set of questions.
  // All questions will be dumped into bucket 0.
  explicit LeitnerBox(QuestionSet&& questions);

  ABSL_MUST_USE_RESULT size_t Size() const { return question_set_.size(); };
  ABSL_MUST_USE_RESULT size_t BucketSize(size_t index) const {
    return buckets_[index].size();
  };

  ABSL_MUST_USE_RESULT Question const* Next(size_t index) const;

  void Shuffle(size_t index);
  void MoveToFirst(size_t index);
  void MoveUp(size_t index);

  void PrintBucket(size_t index) const {
    std::cout << absl::Substitute("Bucket $0", index) << std::endl;
    for (auto q : buckets_[index]) {
      std::cout << "  ";
      q->print();
    }
  }

 private:
  // Not copyable
  LeitnerBox(const LeitnerBox&) = delete;
  LeitnerBox(LeitnerBox&&) = delete;
  LeitnerBox& operator=(const LeitnerBox&) = delete;
  LeitnerBox& operator=(LeitnerBox&&) = delete;

  // Add 1 since buckets are 1-indexed.
  static constexpr size_t total_buckets = last_bucket + 1;

  using Bucket = std::vector<Question const*>;
  using Buckets = std::vector<Bucket>;

  // We own the QuestionSet, so we can put ptrs into it in the buckets.
  // Since it's const, the ptrs will never change.
  QuestionSet const question_set_;
  Buckets buckets_;
};

}  // namespace spacer

#endif  // SPACER_LIB_LEITNER_BOX_H
