#ifndef SPACER_LIB_SCHEDULE_H
#define SPACER_LIB_SCHEDULE_H

#include <deque>

namespace spacer {

class Schedule {
 public:
  Schedule(size_t num_buckets);

  // No copying/moving
  Schedule(const Schedule &) = delete;
  Schedule(Schedule &&) = delete;
  Schedule &operator=(const Schedule &) = delete;
  Schedule &operator=(Schedule &&) = delete;

  size_t Current() const;
  void PopCurrent();

  void Print() const;

 private:
  using Bucket = std::deque<size_t>;
  using Buckets = std::deque<Bucket>;

  Buckets buckets_;
};

}  // namespace spacer

#endif  // SPACER_LIB_SCHEDULE_H
