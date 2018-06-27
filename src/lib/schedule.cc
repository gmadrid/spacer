#include "schedule.h"

#include <iostream>

namespace spacer {

Schedule::Schedule(size_t num_buckets) {
  buckets_.resize(num_buckets);
  for (int i = 0; i < num_buckets; ++i) {
    buckets_[i].push_back(i + 1);
  }
}

size_t Schedule::Current() const { return buckets_.front().front(); }

void Schedule::PopCurrent() {
  auto val = Current();
  if (buckets_.size() < val + 1) {
    buckets_.resize(val + 1);
  }
  buckets_[val].push_back(val);

  buckets_.front().pop_front();

  if (buckets_.front().empty()) {
    buckets_.pop_front();
    sort(buckets_.front().begin(), buckets_.front().end());
    reverse(buckets_.front().begin(), buckets_.front().end());
  }
}

void Schedule::Print() const {
  using std::cout;
  using std::endl;

  for (auto const &bucket : buckets_) {
    for (auto val : bucket) {
      cout << val << " ";
    }
    cout << "/";
  }
  cout << endl;
}

}  // namespace spacer
