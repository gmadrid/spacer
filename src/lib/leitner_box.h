#ifndef SPACER_LIB_LEITNER_BOX_H
#define SPACER_LIB_LEITNER_BOX_H

#include <vector>

#include "question.h"

namespace spacer {

class LeitnerBox {
 public:
  // Make a box from a set of questions.
  // All questions will be dumped into bucket 0.
  explicit LeitnerBox(QuestionSet questions);

  // Not copyable
  LeitnerBox(const LeitnerBox&) = delete;
  LeitnerBox(LeitnerBox&&) = delete;
  LeitnerBox& operator=(const LeitnerBox&) = delete;
  LeitnerBox& operator=(LeitnerBox&&) = delete;

  size_t Size() const { return _size; };
  size_t BucketSize(size_t index) const { return _buckets[index].size(); };

  Question const& Next(size_t index) const;

  void Shuffle(size_t index);
  void MoveToOne(size_t index);
  void MoveUp(size_t index);

 private:
  using Bucket = std::vector<Question const>;
  using Buckets = std::vector<Bucket>;

  QuestionSet const _question_set;
  Buckets _buckets;
  size_t _size;
};

}  // namespace spacer

#endif  // SPACER_LIB_LEITNER_BOX_H
