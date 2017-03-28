#include <iostream>
#include <vector> 
#include <algorithm>
#include <cassert>

using namespace std;

template <class TIter>
void bubble_sort(TIter begin, TIter end) {
  if (begin == end) {
    return;
  }
  
  TIter sorted_begin = end - 1;
  while (begin < sorted_begin) {
    assert(sorted_begin < end);
    assert(is_sorted(sorted_begin, end));
    auto j = begin;
    
    while (j < sorted_begin) {
      if (*(j+1) < *j) {
        iter_swap(j+1, j);
      }
    ++j;
    }
    --sorted_begin;
    assert(is_sorted(sorted_begin, end)); 
  } 
}
 
template <class TExpected, class TFunc, class TParam> 
void test(TExpected exp, TFunc func, TParam param) {
  auto result = func(param);
  if (exp != result) {
    cerr << "FAILED" << endl;
    return;
  }
  cout << "PASSED!!!" << endl;
}

void test_sort() { 
  typedef vector<int> Array;
  auto sort = [](const vector<int>& v) {
  auto u = v;
  bubble_sort(u.begin(), u.end());
  return u;
  };
  
  test(Array(), sort, Array());
  test(Array(5), sort, Array(5));
  test(Array({4, 5}), sort, Array({5, 4}));
  test(Array({5, 5}), sort, Array({5, 5}));
  test(Array({3, 4, 5, 5}), sort, Array({5, 4, 3, 5}));
  
}

int main() {
    test_sort();
    return 0;
}
