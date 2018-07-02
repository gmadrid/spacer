#include "../lib/question.h"

#include "gtest/gtest.h"

#include "nlohmann/json.hpp"

#include "../lib/json_helpers.h"

namespace spacer {
namespace tests {

TEST(Question, Default) {
  Question q;

  EXPECT_EQ("", q.QuestionString());
  EXPECT_EQ("", q.Answer());
}

TEST(Question, BasicAccessors) {
  Question q("QQ", "AA");
  EXPECT_EQ("QQ", q.QuestionString());
  EXPECT_EQ("AA", q.Answer());
}

TEST(Question, Equality) {
  Question q1("Q1", "A1");
  Question q2("Q2", "A2");
  Question copy_of_q1(q1);

  EXPECT_EQ(Question(), Question());
  EXPECT_EQ(q1, q1);
  EXPECT_EQ(q2, q2);
  EXPECT_EQ(q1, copy_of_q1);

  EXPECT_NE(q1, q2);
  EXPECT_NE(q1, Question());
}

TEST(Question, CaseSensitivity) {
  Question q("QQ", "AnSwEr");

  EXPECT_TRUE(q.MatchAnswer("answer"));
  EXPECT_TRUE(q.MatchAnswer("ANSWER"));
  EXPECT_TRUE(q.MatchAnswer("aNsWeR"));
}

TEST(Question, Json) {
  auto q = Question("QQ", "Answer");
  json j = q;
  Question q2 = j;
  ASSERT_EQ(q, q2);
}

}  // namespace tests
}  // namespace spacer
