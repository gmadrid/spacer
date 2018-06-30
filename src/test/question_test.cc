#include "../lib/question.h"

#include "gtest/gtest.h"

namespace spacer {
namespace tests {

TEST(Question, CaseSensitivity) {
  auto q = Question("ID", "QQ", "AnSwEr");

  EXPECT_TRUE(q.Match("answer"));
  EXPECT_TRUE(q.Match("ANSWER"));
  EXPECT_TRUE(q.Match("aNsWeR"));
}

}  // namespace tests
}  // namespace spacer
