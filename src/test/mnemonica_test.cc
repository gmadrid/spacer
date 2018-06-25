#include "../lib/mnemonica.h"

#include "gtest/gtest.h"

namespace spacer {
namespace tests {

using std::string;
using std::vector;

TEST(Mnemonica, AllCardsInQuestionSet) {
  auto const &m = mnemonica();

  EXPECT_EQ(52, m.size());

  vector<string> suits{"S", "C", "H", "D"};
  vector<string> pips{"A", "2", "3", "4", "5", "6", "7",
                      "8", "9", "T", "J", "Q", "K"};

  for (auto const &suit : suits) {
    for (auto const &pip : pips) {
      auto val = pip + suit;
      auto found = std::find_if(
          m.begin(), m.end(),
          [val](Question const &question) { return val == question.answer(); });
      EXPECT_NE(found, m.end());
    }
  }
}

TEST(Mnemonica, AllKeysUnique) {
  auto const &m = mnemonica();

  for (auto i = begin(m); i != end(m); ++i) {
    auto found = std::find_if(i + 1, end(m), [i](Question const &question) {
      return i->id() == question.id();
    });
    EXPECT_EQ(found, end(m));
  }
}

TEST(Mnemonica, CardsInOrder) {
  auto const &m = mnemonica();

  int last = 0;
  for (auto const &question : m) {
    int val = stoi(question.question());
    ASSERT_LT(last, val);
    last = val;
  }
}

}  // namespace tests
}  // namespace spacer
