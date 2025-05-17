#include <functional>

template <class It, class Compare = std::less<>>
void insertion_sort(It first, It last, Compare cmp = Compare{}) {
  for (auto i = first + 1; i != last; ++i) {
    auto key = *i;
    auto j = i;

    while (j != first && cmp(key, *(j - 1))) {
      *j = *(j - 1);
      --j;
    }

    *j = key;
  }
}