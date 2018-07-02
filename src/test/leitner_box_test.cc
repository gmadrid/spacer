#include "../lib/leitner_box.h"

#include "absl/strings/substitute.h"
#include "gtest/gtest.h"

#include "../lib/json_helpers.h"

namespace spacer {
namespace tests {

using std::string;
using std::vector;

std::string Q(size_t index) { return absl::Substitute("Question $0", index); }

LeitnerBox SimpleTestSet(size_t size) {
  QuestionSet questions;

  for (int i = 0; i < size; ++i) {
    questions.emplace_back(Q(i), absl::Substitute("Answer $0", i));
  }

  LeitnerBox result;
  result.AddQuestions(questions);

  return result;
}

TEST(LeitnerBox, Empty) {
  // Basically, make sure that nothing crashes.
  LeitnerBox lb{};
  EXPECT_EQ(0, lb.Size());
  for (int i = LeitnerBox::waiting_bucket; i <= LeitnerBox::last_bucket; ++i) {
    lb.Shuffle(i);
    EXPECT_EQ(0, lb.BucketSize(i));
  }
  lb.MoveToFirst(0);
  lb.MoveUp(1);
}

TEST(LeitnerBox, StartsInBucket0) {
  size_t size = 34;
  LeitnerBox lb(SimpleTestSet(size));
  EXPECT_EQ(size, lb.Size());
  EXPECT_EQ(lb.Size(), lb.BucketSize(0));
}

TEST(LeitnerBox, NextSimple) {
  size_t size = 3;
  LeitnerBox lb(SimpleTestSet(size));

  auto q = lb.Next(0);
  EXPECT_EQ(q.QuestionString(), Q(size - 1));
}

TEST(LeitnerBox, SimpleMoves) {
  size_t size = 5;
  LeitnerBox lb(SimpleTestSet(size));
  EXPECT_EQ(size, lb.BucketSize(0));

  auto q0 = lb.Next(0);
  lb.MoveToFirst(0);
  EXPECT_EQ(size - 1, lb.BucketSize(0));
  EXPECT_EQ(1, lb.BucketSize(1));

  auto q1 = lb.Next(0);
  EXPECT_NE(q0, q1);

  auto q2 = lb.Next(1);
  EXPECT_EQ(q0, q2);
}

TEST(LeitnerBox, DeeperMoves) {
  size_t size = 11;
  LeitnerBox lb(SimpleTestSet(size));
  EXPECT_EQ(size, lb.BucketSize(0));

  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);

  lb.MoveUp(1);
  lb.MoveUp(1);
  lb.MoveUp(1);
  lb.MoveUp(2);

  EXPECT_EQ(5, lb.BucketSize(0));
  EXPECT_EQ(3, lb.BucketSize(1));
  EXPECT_EQ(2, lb.BucketSize(2));
  EXPECT_EQ(1, lb.BucketSize(3));
}

TEST(LeitnerBox, Json) {
  size_t size = 11;
  LeitnerBox lb(SimpleTestSet(size));
  EXPECT_EQ(size, lb.BucketSize(0));

  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);
  lb.MoveToFirst(0);

  lb.MoveUp(1);
  lb.MoveUp(1);
  lb.MoveUp(1);
  lb.MoveUp(2);

  json j = lb;
  LeitnerBox lb2 = j;
  EXPECT_EQ(lb, lb2);
}

}  // namespace tests
}  // namespace spacer
