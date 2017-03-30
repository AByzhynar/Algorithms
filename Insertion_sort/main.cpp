#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <class TIter>
void insertion_sort(TIter begin, TIter end) {
  if (begin == end) {
    return;
  }

//  TIter sorted_end = begin;
//  while (sorted_end < end) {
//    if (is_sorted(begin, sorted_end)) {
//      sorted_end++;
//    } else {
//      break;
//    }
//  }
  auto pivot = begin + 1;
  while(pivot < end) { //base condition 1
      // [b, pivot) [pivot) [pivot+1, e)
      assert(is_sorted(begin, pivot));
      auto i = pivot;
      while(begin < i && *i < *(i -1) ) { // base condition 2
          assert(is_sorted(begin, i) && is_sorted(i, pivot));
          std::iter_swap(i, i - 1);
          --i;
          assert(is_sorted(begin, i) && is_sorted(i, pivot));
      }

      ++pivot;
      assert(is_sorted(begin, pivot));
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
  insertion_sort(u.begin(), u.end());
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
