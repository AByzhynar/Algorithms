#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename TParam1, typename TParam2>
TParam1 lower_bound_my(TParam1 begin, TParam1 end, const TParam2& key) {
  assert(begin <= end && std::is_sorted(begin, end));
  while (begin < end) {
    TParam1 m = begin + (end - begin) / 2;
    if (*m < key) {
      begin = ++m;
    } else {
      end = m;
    }
  }
  return begin;
}

template <typename TParam1, typename TParam2>
TParam1 upper_bound_my(TParam1 begin, TParam1 end, const TParam2& key) {
  assert(begin <= end && std::is_sorted(begin, end));
  while (begin < end) {
    TParam1 m = begin + (end - begin) / 2;
    if (key < *m) {
      end = m;
    } else {
      begin = ++m;
    }
  }

  return begin;
}

template <typename TParam1, typename TParam2>
TParam1 binary_search_helper(TParam1 begin, TParam1 end, const TParam2 key) {
  assert(std::is_sorted(begin, end));

  TParam1 new_begin = lower_bound_my(begin, end, key);
  return new_begin != end && !(key < *new_begin) ? new_begin : end;
}

template <class TFunc,
          class TResult,
          class TParam1,
          class TParam2,
          class TParam3>
void test(TResult expected, TFunc f, TParam1 p1, TParam2 p2, TParam3 key) {
  auto got = f(p1, p2, key);
  if (got != expected) {
    cerr << "FAILED!!!" << endl;
    //    cerr << "Container to search in : " << p1 << endl;
    //    cerr << "Value to search: " << p2 << endl;
    //    cerr << "Expected value index: " << expected << endl;
    //    cerr << "Actual value index: " << got << endl;
    return;
  }
  cout << "PASSED!!!" << endl;
}

template <class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expected, TFunc f, TParam1 p1, TParam2 p2) {
  auto got = f(p1, p2);
  if (got != expected) {
    cerr << "FAILED!!!" << endl;
    return;
  }
  cout << "PASSED!!!" << endl;
}

void test_search() {
  typedef vector<int> Array;

  auto lb_search = lower_bound_my<Array::iterator, int>;

  auto bin_search = [](const vector<int>& v, const int key) {
    auto r = binary_search_helper(v.begin(), v.end(), key);
    return r != v.end() ? r - v.begin() : -1;
  };

  auto ub_search = upper_bound_my<Array::iterator, int>;

  // Key does not exist
  const int key = 8;
  Array a;
  //  test(a.end(), lb_search, a.begin(), a.end(), key); // Degerate (empty
  //  array)

  //  Array b({8});
  //  test(b.begin(), lb_search, b.begin(), b.end(), key);

  //  Array c({5});
  //  test(c.end(), lb_search, c.begin(), c.end(), key);

  //  Array d({5, 6, 7, 8, 9, 10});
  //  Array::iterator found = std::find(d.begin(), d.end(), key);
  //  test(found, lb_search, d.begin(), d.end(), key);

  //  Array e({5, 6, 7, 9, 10});
  //  Array::iterator found2 = std::find(e.begin(), e.end(), key + 1);
  //  test(found2, lb_search, e.begin(), e.end(), key);

  Array d({5, 6, 7, 8, 8, 8, 9, 10});
  Array::iterator found = std::find(d.begin(), d.end(), key);
  test(found, lb_search, d.begin(), d.end(), key);
  test(found + 3, ub_search, d.begin(), d.end(), key);

  test(-1, bin_search, a, key);  // Trivial1  1 element array
  test(-1,
       bin_search,
       Array({key - 1, key + 1}),
       key);  // Trivial2 (2 elements array)

  // General
  test(-1, bin_search, Array({1, 2, 3, 4, 5, 6, 7}), key);
  test(-1, bin_search, Array({9, 10, 11, 12}), key);

  test(0, bin_search, Array({key}), key);  // Trivial1 1 element array
  test(0,
       bin_search,
       Array({key, key + 1}),
       key);  // Trivial2 (2 elements array)
  test(1,
       bin_search,
       Array({key - 1, key}),
       key);  // Trivial2 (2 elements array)

  test(8, bin_search, Array({0, 1, 2, 3, 4, 5, 6, 7, key}), key);  // General
  test(0, bin_search, Array({key, 9, 10, 11, 12}), key);           // General
}

int main() {
  test_search();
  return 0;
}
