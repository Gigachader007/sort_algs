#include <functional>

template <class It, class Compare = std::less<>>
void quick_sort(It first, It last, Compare cmp = Compare{}) {
  if (last - first <= 1)
    return;

  auto pivot = *first;
  auto i = first + 1;
  auto j = last - 1;

  while (i <= j) {
    while (i <= j && !cmp(pivot, *i))
      ++i;
    while (i <= j && cmp(pivot, *j))
      --j;
    if (i < j) {
      auto temp = *i;
      *i = *j;
      *j = temp;
    }
  }

  auto temp = *first;
  *first = *j;
  *j = temp;

  quick_sort(first, j, cmp);
  quick_sort(j + 1, last, cmp);
}