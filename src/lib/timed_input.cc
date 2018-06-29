#include "timed_input.h"

#include <sys/select.h>

#include <iostream>

#include "absl/strings/str_cat.h"

namespace spacer {

using absl::StrCat;
using std::cout;
using std::flush;
  using std::string;

TimedInput::TimedInput(time_t timeout_secs) : timeout_{ timeout_secs, 0 } {}

  bool TimedInput::WaitForInput(absl::string_view prompt) {
    input_valid_ = false;
   fd_set input_set;
   FD_ZERO(&input_set);
   FD_SET(0, &input_set);

   cout << StrCat(prompt, " (", timeout_.tv_sec, " secs): ") << flush;

   auto result = select(1, &input_set, NULL, NULL, &timeout_);
   if (result < 1) {
     return false;
   }

   std::cin >> input_;
   input_valid_ = true;
   return true;
  }

  string TimedInput::Input() {
    assert(input_valid_);
    return input_;
  }
  
// bool TimedInput::GetInput(absl::string_view prompt, std::string *output) {
//   fd_set input_set;
//   FD_ZERO(&input_set);
//   FD_SET(0, &input_set);

//   cout << StrCat(prompt, " (", timeout_.tv_sec, " secs): ") << flush;

//   auto result = select(1, &input_set, NULL, NULL, &timeout_);
//   if (result < 1) {
//     return false;
//   }

//   std::cin >> *output;
//   return true;
// }

}  // namespace spacer
