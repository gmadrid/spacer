#ifndef SPACER_LIB_SCHEDULE_H
#define SPACER_LIB_SCHEDULE_H

#include <deque>

#include "absl/base/attributes.h"

namespace spacer {

class Schedule {
 public:
  Schedule(size_t num_buckets);

  ABSL_MUST_USE_RESULT size_t Current() const;
  void PopCurrent();

  void Print() const;

 private:
  // No copying/moving
  Schedule(const Schedule &) = delete;
  Schedule(Schedule &&) = delete;
  Schedule &operator=(const Schedule &) = delete;
  Schedule &operator=(Schedule &&) = delete;

  using Bucket = std::deque<size_t>;
  using Buckets = std::deque<Bucket>;

  Buckets buckets_;
};

}  // namespace spacer

#endif  // SPACER_LIB_SCHEDULE_H
