#include <vector>

#include <sort/sort.hpp>
#include <iostream>

#include <algorithm>

int main() {
  {
    std::vector<int> v1 = {1, 2, 5};
    std::vector<int> v2 = {5, 6, 9};

    std::vector<int> result(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    
    for(int v : result){
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    merge_sort(vec.begin(), vec.end(), vec.begin());
    for(int v : vec){
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    inplace_merge_sort(v.begin(), v.end());
    for(int val : v){
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    heap_sort(v.begin(), v.end());
    for(int val : v){
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    quick_sort(v.begin(), v.end());
    for(int val : v){
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    insertion_sort(v.begin(), v.end());
    for(int val : v){
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    std::sort(v.begin(), v.end());
    for(int val : v){
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    std::stable_sort(v.begin(), v.end());
    for(int val : v){
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
  {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};
    bogo_sort(v.begin(), v.end());
    for(int val : v){
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
}