#include "../lib/leitner_box.h"

#include "absl/strings/substitute.h"
#include "gtest/gtest.h"

namespace spacer {
namespace tests {

using std::string;
using std::vector;

std::string Key(size_t index) { return absl::Substitute("Key $0", index); }

QuestionSet SimpleTestSet(size_t size) {
  QuestionSet result;

  for (int i = 0; i < size; ++i) {
    result.emplace_back(Key(i), absl::Substitute("Question $0", i),
                        absl::Substitute("Answer $0", i));
  }

  return result;
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
  EXPECT_EQ(q->Id(), Key(size - 1));
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

}  // namespace tests
}  // namespace spacer
