#include "question.h"

namespace spacer {

using std::string;

bool Question::Match(absl::string_view match) const {
  string qlower(Answer());
  transform(qlower.begin(), qlower.end(), qlower.begin(), ::tolower);
  string mlower(match);
  std::transform(mlower.begin(), mlower.end(), mlower.begin(), ::tolower);

  return qlower == mlower;
}

}  // namespace spacer
