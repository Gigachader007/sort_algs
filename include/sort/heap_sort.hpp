#pragma once

#include <functional>

template <class It, class Compare>
void sift_down(It first, It last, It root, Compare cmp) {
  while (root < last) {
    auto largest = root;
    auto left = first + 2 * (root - first) + 1;
    auto right = left + 1;

    if (left < last && cmp(*largest, *left)) {
      largest = left;
    }
    if (right < last && cmp(*largest, *right)) {
      largest = right;
    }

    if (largest == root) {
      break;
    }

    auto temp = *root;
    *root = *largest;
    *largest = temp;
    root = largest;
  }
}

template <class It, class Compare = std::less<>>
void heap_sort(It first, It last, Compare cmp = Compare{}) {

  for (auto i = (last - first) / 2 - 1; i >= 0; --i) {
    sift_down(first, last, first + i, cmp);
  }

  while (last - first > 1) {
    --last;
    auto temp = *first;
    *first = *last;
    *last = temp;
    sift_down(first, last, first, cmp);
  }
}