#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <class TIter>
void merge_sort(TIter begin, TIter end, TIter buff) {
  auto size = end - begin;
  if (size > 1) {
    auto m = begin + (end - begin) / 2;
    merge_sort(begin, m, buff);
    merge_sort(m, end, buff + (size / 2));
    std::copy(buff, buff + size, begin);
    merge(begin, m, end, buff);
  } else {
    std::copy(begin, end, buff);
  }
}

template <class TIter>
void merge(TIter begin, TIter median, TIter end, TIter buff) {
//  assert(is_sorted(begin, median));
//  assert(is_sorted(median, end));

  auto size = end - begin;
  const auto old = buff;
  auto end1 = median;
  while (begin < end1 && median < end) {
      *buff++ = *begin < *median ? *begin++ : *median++;
//    if (*second_begin < *begin) {
//      *buff = *second_begin++;
//    } else {
//      *buff == *begin++;
//    }
//    ++buff;
  }
  buff = copy(begin, end1, buff);
  buff = copy(median, end, buff);
  assert(buff-old == size);
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
    auto u = v;
    merge_sort(v.begin(), v.end(), u.begin());
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
