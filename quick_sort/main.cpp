#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


template <class TIter>
void quick_sort(TIter begin, TIter end) {
  if (end - begin > 1) {
    auto p = partition1(begin, begin, end);
   // assert(std::max(*begin, *p) < *p && *p < std::min((*p+1), end))
    quick_sort(begin, p);
    quick_sort(p + 1, end);
  }
}

template <class TIter>
TIter partition1(TIter begin, TIter p, TIter end) {
  assert(begin < end);
  auto pivot = *p;
  swap(*(end - 1), *p);
  auto ub = begin;
  auto ue = end - 1;
  // [b, ub) [ub, ue) [ue, e)
  // [<p) [] [ p <= )
  while (ub < ue) {
    if (*ub < pivot) {
      ++ub;
    } else {
      --ue;
      swap(*ub, *ue);
    }
  }
  swap(*ub, *(end - 1));
  return ub;
}

template <class TIter>
TIter partition2(TIter begin, TIter p, TIter end) {
  assert(begin < end);
  auto pivot = *p;
  swap(*(end - 1), *p);
  auto b2 = begin;
  auto e2 = begin;
  // [b, ub) [ub, ue) [ue, e)
  // [<p) [] [ p <= )
  while (e2 + 1 < end) {
      if (*e2 < pivot) {
        swap(*b2, *e2);
        ++b2;
      }
    ++e2;
  }

  swap(*b2, *(end - 1));
  return b2;
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
  auto sort = [](Array& v) {
    quick_sort(v.begin(), v.end());
    return v;
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
