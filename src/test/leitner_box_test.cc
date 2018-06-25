#include "../lib/leitner_box.h"

#include "gtest/gtest.h"

#include "../lib/mnemonica.h"

namespace spacer {
namespace tests {

using std::string;
using std::vector;

TEST(LeitnerBox, StartsInBucket0) {
  auto m = mnemonica();
  LeitnerBox lb(m);
  EXPECT_EQ(m.size(), lb.Size());
  EXPECT_EQ(lb.Size(), lb.BucketSize(0));
}

QuestionSet SimpleTestSet(size_t size) {
  QuestionSet result;

  for (size_t i = 0; i < size; ++i) {
    //      result.emplace_back(Substitute("Id$0", i), Substitute(
  }

  return result;
}

TEST(LeitnerBox, NextSimple) {}

}  // namespace tests
}  // namespace spacer
