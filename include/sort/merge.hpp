#pragma once

#include <functional>

template <class It, class Out, class Compare = std::less<>>
Out merge(It first1, It last1, It first2, It last2, Out result,
          Compare cmp = Compare{}) {
  while (first1 != last1 && first2 != last2) {

    if (cmp(*first1, *first2)) {
      *result = *first1;
      ++first1;
    } else {
      *result = *first2;
      ++first2;
    }
    ++result;
  }

  while (first1 != last1) {
    *result = *first1;
    ++first1;
    ++result;
  }

  while (first2 != last2) {
    *result = *first2;
    ++first2;
    ++result;
  }

  return result;
}