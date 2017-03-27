#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename TParam1>
TParam1 min_element_my(TParam1 begin, TParam1 end) {
   auto result = begin;
  while (begin < end) {
      // // [) = [processe)[current][unprocessed)
      // assert(tmp -s minimum from [processed)
    if (*begin < *result) {
      result = begin;
    }
      ++begin;
       // assert(tmp -s minimum from [processed)
  }
  return result;
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



  // Key does not exist


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
  Array a;
  Array::iterator it = min_element_my(a.begin(), a.end());
  assert(it == a.end());
  Array d({5, 6, 7, -4, 8, 8, 8, 9, 10});
  Array::iterator it2 = min_element_my(d.begin(), d.end());
  cout << "Result: " << *it2 << endl;



}

int main() {
  test_search();
  return 0;
}
