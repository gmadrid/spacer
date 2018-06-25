#ifndef SPACER_LIB_QUESTIONID_H
#define SPACER_LIB_QUESTIONID_H

#include <string>
#include <string_view>

namespace spacer {

using QuestionId = const std::string;

class Question {
 public:
  Question(QuestionId id, std::string_view question, std::string_view answer)
      : _question_id(id), _question(question), _answer(answer) {}

  Question(Question const &) = default;
  Question(Question &&) = default;
  Question &operator=(Question const &) = default;
  Question &operator=(Question &&) = default;

  QuestionId const &id() const { return _question_id; }
  std::string const &question() const { return _question; }
  std::string const &answer() const { return _answer; }

 private:
  const QuestionId _question_id;
  const std::string _question;
  const std::string _answer;
};

using QuestionSet = std::vector<Question const>;

}  // namespace spacer

#endif  // SPACER_LIB_QUESTIONID_H
