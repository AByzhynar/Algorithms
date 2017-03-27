#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename TParam1>
void bubble_sort_my(TParam1 begin, TParam1 end) {
  if (begin == end) {
    return;
  }
  TParam1 sorted_begin = end - 1;
  while (begin < sorted_begin) {
    // [sorted) U [unsorted) = [b, i) U [i. e)
    assert(sorted_begin < end);
    assert(is_sorted(sorted_begin, end));

    auto j = begin;
    while ( j < sorted_begin) {
      // [unsorted) = [i] U [i+1, j) U [j, e)
      //assert(std::max_element(begin, j+1) == j);

      if (*(j + 1) < *j) {
        std::iter_swap(j + 1, j);
      }
      ++j;
      //assert(std::max_element(begin, j+1) == j);
    }
    --sorted_begin;
    assert(is_sorted(sorted_begin, end));
  }
}

// template <typename TParam1>
// void selection_sort_my(TParam1 begin, TParam1 end) {
//  for (auto i = begin; i < end; ++i) {
//    assert(is_sorted(begin, i));
//    // [sorted) U [unsorted) = [b, i) U [i. e)
//    swap(*i, *min_element(i, end));
//  }
//}

template <class TFunc, class TResult, class TParam1>
void test(TResult expected, TFunc f, TParam1 p1) {
  auto got = f(p1);
  if (got != expected) {
    cerr << "FAILED!!!" << endl;
    return;
  }
  cout << "PASSED!!!" << endl;
}

void test_search() {
  typedef vector<int> Array;
  // Key does not exist
  auto sort = [](const vector<int>& v) {
    auto u = v;
    bubble_sort_my(u.begin(), u.end());
    return u;
  };

  test(Array(), sort, Array());
  test(Array({8}), sort, Array({8}));
  test(Array({1, 2}), sort, Array({2, 1}));
  test(Array({0, 1, 2, 3, 4, 5}), sort, Array({2, 1, 0, 5, 4, 3}));
  test(Array({8, 8, 8, 8}), sort, Array({8, 8, 8, 8}));
  test(Array({1, 8, 8, 8, 8}), sort, Array({8, 8, 1, 8, 8}));
}

int main() {
  test_search();
  return 0;
}
