#pragma once

#include "merge.hpp"

template <class It, class Out, class Compare = std::less<>>
Out merge_sort(It first, It last, Out out, Compare cmp = Compare{}) {
  auto size = std::distance(first, last);

  if (size <= 1) {
    if (size == 1) {
      *out = *first;
      ++out;
    }
    return out;
  }

  auto mid = first;
  std::advance(mid, size / 2);

  std::vector<typename std::iterator_traits<It>::value_type> temp(size);

  auto temp_out = temp.begin();
  temp_out = merge_sort(first, mid, temp_out, cmp);
  temp_out = merge_sort(mid, last, temp_out, cmp);

  return merge(temp.begin(), temp.begin() + std::distance(first, mid),
               temp.begin() + std::distance(first, mid), temp.end(), out, cmp);
}