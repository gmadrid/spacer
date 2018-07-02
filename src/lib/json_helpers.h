#ifndef SPACER_LIB_UTIL_H
#define SPACER_LIB_UTIL_H

#include <iostream>

#include "absl/meta/type_traits.h"
#include "nlohmann/json.hpp"

namespace spacer {

template <typename T>
typename absl::enable_if_t<std::is_pointer<T>::value> print_json(T t) {
  nlohmann::json j = *t;
  std::cout << j;
}

template <typename T>
typename absl::enable_if_t<!std::is_pointer<T>::value> print_json(T t) {
  nlohmann::json j = t;
  std::cout << j;
}

template <typename T>
void pretty_print_json(const T &t) {
  nlohmann::json j = t;
  std::cout << j.dump(2) << std::endl;
}

}  // namespace spacer

#endif  // SPACER_LIB_UTIL_H
