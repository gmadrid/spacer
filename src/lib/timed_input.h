#ifndef SPACER_LIB_TIMED_INPUT_H
#define SPACER_LIB_TIMED_INPUT_H

#include <sys/time.h>

#include <string>

#include "absl/base/attributes.h"
#include "absl/strings/string_view.h"

namespace spacer {

class TimedInput {
 public:
  TimedInput(time_t timeout_secs);

  // Returns true iff input is available before the timeout.
  ABSL_MUST_USE_RESULT bool WaitForInput(absl::string_view prompt);

  // If WaitForInput returned true, then get the input string.
  ABSL_MUST_USE_RESULT std::string Input();

 private:
  TimedInput(const TimedInput &) = delete;
  TimedInput(TimedInput &&) = delete;
  TimedInput &operator=(const TimedInput &) = delete;
  TimedInput &operator=(TimedInput &&) = delete;

  struct timeval timeout_;

  bool input_valid_ = false;
  std::string input_;
};

}  // namespace spacer

#endif  // SPACER_LIB_TIMED_INPUT_H
