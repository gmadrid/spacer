#include "question.h"

namespace spacer {

using std::string;

constexpr auto id_jkey = "id";
constexpr auto question_jkey = "question";
constexpr auto answer_jkey = "answer";

bool Question::operator==(Question const &rhs) const {
  return Id() == rhs.Id() && QuestionString() == rhs.QuestionString() &&
         Answer() == rhs.Answer();
}

bool Question::MatchAnswer(absl::string_view match) const {
  string qlower(Answer());
  transform(qlower.begin(), qlower.end(), qlower.begin(), ::tolower);
  string mlower(match);
  std::transform(mlower.begin(), mlower.end(), mlower.begin(), ::tolower);

  return qlower == mlower;
}

void to_json(json &j, Question const &q) {
  j[id_jkey] = q.Id();
  j[question_jkey] = q.QuestionString();
  j[answer_jkey] = q.Answer();
}

void from_json(json const &j, Question &q) {
  string id = j[id_jkey];
  string question = j[question_jkey];
  string answer = j[answer_jkey];

  q = Question(id, question, answer);
}

}  // namespace spacer
