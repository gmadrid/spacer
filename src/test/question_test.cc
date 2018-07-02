#include "../lib/question.h"

#include "gtest/gtest.h"

#include "nlohmann/json.hpp"

#include "../lib/json_helpers.h"

namespace spacer {
namespace tests {

TEST(Question, CaseSensitivity) {
  Question q("ID", "QQ", "AnSwEr");

  EXPECT_TRUE(q.MatchAnswer("answer"));
  EXPECT_TRUE(q.MatchAnswer("ANSWER"));
  EXPECT_TRUE(q.MatchAnswer("aNsWeR"));
}

TEST(Question, Json) {
  auto q = Question("ID", "QQ", "Answer");
  json j = q;
  Question q2 = j;
  ASSERT_EQ(q, q2);
}

}  // namespace tests
}  // namespace spacer
