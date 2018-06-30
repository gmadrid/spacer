#ifndef SPACER_LIB_COLORS_H
#define SPACER_LIB_COLORS_H

#include <string>

#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"

namespace spacer {

using std::string;

string color(absl::string_view infix, absl::string_view s) {
  return absl::StrCat("\033[", infix, "m", s, "\033[0m");
}

string yellow(absl::string_view s) { return color("0;33", s); }

string bright_yellow(absl::string_view s) { return color("1;33", s); }

}  // namespace spacer

#endif  // SPACER_LIB_COLORS_H
