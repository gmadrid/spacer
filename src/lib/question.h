#ifndef SPACER_LIB_QUESTION_H
#define SPACER_LIB_QUESTION_H

#include <algorithm>
#include <iostream>
#include <string>

#include "absl/base/attributes.h"
#include "absl/strings/string_view.h"
#include "absl/strings/substitute.h"
#include "nlohmann/json.hpp"

namespace spacer {

using nlohmann::json;

class Question {
 public:
  Question(std::string_view question, std::string_view answer)
      : _question(question), _answer(answer) {}

  Question() = default;
  Question(Question const &) = default;
  Question(Question &&) = default;
  Question &operator=(Question const &) = default;
  Question &operator=(Question &&) = default;

  ABSL_MUST_USE_RESULT bool operator==(Question const &rhs) const;
  ABSL_MUST_USE_RESULT bool operator!=(Question const &rhs) const {
    return !(*this == rhs);
  }

  ABSL_MUST_USE_RESULT bool MatchAnswer(absl::string_view) const;

  ABSL_MUST_USE_RESULT std::string const &QuestionString() const {
    return _question;
  }
  ABSL_MUST_USE_RESULT std::string const &Answer() const { return _answer; }

 private:
  std::string _question;
  std::string _answer;
};

using QuestionSet = std::vector<Question const>;

void to_json(json &j, Question const &q);
void from_json(json const &j, Question &p);

}  // namespace spacer

#endif  // SPACER_LIB_QUESTION_H
