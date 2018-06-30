#ifndef SPACER_LIB_QUESTIONID_H
#define SPACER_LIB_QUESTIONID_H

#include <algorithm>
#include <iostream>
#include <string>

#include "absl/base/attributes.h"
#include "absl/strings/string_view.h"
#include "absl/strings/substitute.h"

namespace spacer {

using QuestionId = std::string const;

class Question {
 public:
  Question(QuestionId id, std::string_view question, std::string_view answer)
      : _question_id(id), _question(question), _answer(answer) {}

  Question(Question const &) = default;
  Question(Question &&) = default;
  ABSL_MUST_USE_RESULT Question &operator=(Question const &) = default;
  ABSL_MUST_USE_RESULT Question &operator=(Question &&) = default;

  ABSL_MUST_USE_RESULT bool Match(absl::string_view) const;

  ABSL_MUST_USE_RESULT QuestionId const &Id() const { return _question_id; }
  ABSL_MUST_USE_RESULT std::string const &QuestionString() const {
    return _question;
  }
  ABSL_MUST_USE_RESULT std::string const &Answer() const { return _answer; }

  void print() const {
    std::cout << absl::Substitute("$0:$1:$2", _question_id, _question, _answer)
              << std::endl;
  }

 private:
  const QuestionId _question_id;
  const std::string _question;
  const std::string _answer;
};

using QuestionSet = std::vector<Question const>;

}  // namespace spacer

#endif  // SPACER_LIB_QUESTIONID_H
