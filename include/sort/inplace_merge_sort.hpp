#include <functional>

template <class It, class Compare = std::less<>>
void inplace_merge_sort(It first, It last, Compare cmp = Compare{}) {
  auto inplace_merge = [](It first, It mid, It last, Compare cmp) {
    while (first != mid && mid != last) {
      if (cmp(*mid, *first)) {
        auto value = *mid;
        for (auto it = mid; it != first; --it) {
          *it = *(it - 1);
        }
        *first = value;
        ++first;
        ++mid;
      } else {
        ++first;
      }
    }
  };

  auto size = std::distance(first, last);

  if (size <= 1) {
    return;
  }

  if (size <= 4) {
    for (auto i = first + 1; i != last; ++i) {
      auto key = *i;
      auto j = i;
      while (j != first && cmp(key, *(j - 1))) {
        *j = *(j - 1);
        --j;
      }
      *j = key;
    }
    return;
  }

  auto mid = first;
  std::advance(mid, size / 2);

  inplace_merge_sort(first, mid, cmp);
  inplace_merge_sort(mid, last, cmp);

  inplace_merge(first, mid, last, cmp);
}