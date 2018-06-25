#include "leitner_box.h"

namespace spacer {
constexpr size_t num_buckets = 7;

LeitnerBox::LeitnerBox(QuestionSet questions)
    : _question_set(questions), _size(questions.size()) {
  // Create all of the buckets
  for (int i = 0; i <= num_buckets; ++i) {
    _buckets.emplace_back();
  }

  // Then, put all of the questions into bucket 0.
  std::copy(questions.begin(), questions.end(),
            std::back_inserter(_buckets[0]));
}

}  // namespace spacer
