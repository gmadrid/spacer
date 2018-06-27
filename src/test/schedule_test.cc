#include "../lib/schedule.h"

#include "absl/strings/substitute.h"
#include "gtest/gtest.h"

namespace spacer {
namespace tests {

TEST(Schedule, Base) {
  Schedule s(7);

  EXPECT_EQ(1, s.Current());
}

TEST(Schedule, FirstPop) {
  Schedule s(4);

  EXPECT_EQ(1, s.Current());
  s.PopCurrent();
  EXPECT_EQ(2, s.Current());
}

TEST(Schedule, Extended) {
  Schedule s(4);

  // 1/2/3/4
  EXPECT_EQ(1, s.Current());
  s.PopCurrent();

  // 2 1/3/4
  EXPECT_EQ(2, s.Current());
  s.PopCurrent();

  // 1/3/4 2
  EXPECT_EQ(1, s.Current());
  s.PopCurrent();

  // 3 1/4 2
  EXPECT_EQ(3, s.Current());
  s.PopCurrent();

  // 1/4 2//3
  EXPECT_EQ(1, s.Current());
  s.PopCurrent();

  // 4 2 1//3
  EXPECT_EQ(4, s.Current());
  s.PopCurrent();

  // 2 1//3//4
  EXPECT_EQ(2, s.Current());
  s.PopCurrent();

  // 1//3 2//4
  EXPECT_EQ(1, s.Current());
  s.PopCurrent();

  // 1/3 2//4
  EXPECT_EQ(1, s.Current());
  s.PopCurrent();

  // 3 2 1//4
  EXPECT_EQ(3, s.Current());
  s.PopCurrent();

  // 2 1//4/3
  EXPECT_EQ(2, s.Current());
  s.PopCurrent();

  // 1//4 2/3
  EXPECT_EQ(1, s.Current());
  s.PopCurrent();

  // 1/4 2/3
  EXPECT_EQ(1, s.Current());
  s.PopCurrent();

  // 4 2 1/3
  EXPECT_EQ(4, s.Current());
}

}  // namespace tests
}  // namespace spacer
