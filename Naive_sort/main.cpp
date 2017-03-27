#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename TParam1>
void naive_sort(TParam1 begin, TParam1 end) {
  for (auto i = begin; i < end; ++i) {
    assert(is_sorted(begin, i));
    // [sorted) U [unsorted) = [b, i) U [i. e)
    for (auto j = i + 1; i < end; ++j) {
      // [unsorted) = [i] U [i+1, j) U [j, e)
      assert(min_element(i, j) == i);
      if (*j < *i) {
        swap(*i, *j);
      }
      assert(min_element(i, j) == i);
    }
    assert(is_sorted(begin, i + 1));
  }
}

template <typename TParam1>
void selection_sort_my(TParam1 begin, TParam1 end) {
  for (auto i = begin; i < end; ++i) {
    assert(is_sorted(begin, i));
    // [sorted) U [unsorted) = [b, i) U [i. e)
    swap(*i, *min_element(i, end));
  }
}

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
    selection_sort_my(u.begin(), u.end());
    return u;
  };

  test(Array(), sort, Array());
  test(Array({8}), sort, Array({8}));
  test(Array({1, 2}), sort, Array({2, 1}));
  test(Array({1, 2, 3, 4, 5}), sort, Array({2, 1, 5 ,4 ,3}));
  test(Array({8, 8 ,8 ,8}), sort, Array({8, 8 , 8 ,8 }));
  test(Array({1, 8, 8 ,8 ,8}), sort, Array({8, 8 ,1, 8 ,8 }));
}

int main() {
  test_search();
  return 0;
}
