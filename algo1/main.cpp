#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    for(auto& x : v) {
        o << x << ", ";
    }
    return o << "]";
}



int binary_search_helper(const vector<int>& v, const int key, size_t begin , size_t end) {




  assert(std::is_sorted(v.begin(), v.end()));
  if (begin == end) {
      return -1;
  }
  if (end - begin == 1)  {
      if (v[begin] == key) {
          return begin;
      }
      else {
          return -1;
      }
  }

  size_t m = (begin + end) / 2;
  assert((m-begin) + (end-m) == (end-begin));
  // [0, s) = [0, m) U [m, s)
  if (key < v[m]) {
  return binary_search_helper(v, begin, m, key);
  } else if (v[m] < key) {
  return binary_search_helper(v, m, end, key);
  } else {
      return m;
  }
}

int SearchElement(vector<int>& array, const int key) {
    int i = 0;
    array.push_back(key);
    while(array[i] != key) {
        ++i;
    }
    array.pop_back();
    if(i != array.size()) {
        return i;
    }
    return (-1);
}


template <class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expected ,TFunc f, TParam1 p1, TParam2 p2) {
    auto got = f(p1, p2);
    if (got != expected) {
        cerr << "FAILED!!! f(" << p1 << ", " << p2 << ")" << endl;
        cerr << "Container to search in : " << p1 << endl;
        cerr << "Value to search: " << p2 << endl;
        cerr << "Expected value index: " << expected << endl;
        cerr << "Actual value index: " << got << endl;
    }

}


template <class TFunc, class TResult, class TParam1>
void test(TResult expected ,TFunc f, TParam1 p1) {
    auto got = f(p1);
    if (got != expected) {
        cerr << "FAILED!!! f(" << p1 << ")" << endl;
        cerr << "Expected value index: " << expected << endl;
        cerr << "Actual value index: " << got << endl;
    }

}

void test_search() {
  typedef vector<int> Array;
  const int expected_index = 8;
  auto search = SearchElement;
  // Key does not exist

  test(-1, search, Array(), expected_index); // Degerate (empty array)
  test(-1, search, Array({expected_index - 1}), expected_index); // Trivial1  1 element array
  test(-1, search, Array({expected_index - 1, expected_index + 1}), expected_index); // Trivial2 (2 elements array)

  // General
  test(-1, search, Array({1, 2, 3, 4, 5, 6, 7}), expected_index);
  test(-1, search, Array({9, 10, 11, 12}), expected_index);
  test(-1, search, Array({4, 1, 2, 7, 10}), expected_index);

  // Key exists
  // Degerate (empty array)
  // Not applicable

  test(0, search, Array({expected_index}), expected_index); // Trivial1  1 element array
  test(0, search, Array({expected_index, expected_index + 1}), expected_index); // Trivial2 (2 elements array)
  test(1, search, Array({expected_index - 1, expected_index}), expected_index); // Trivial2 (2 elements array)
  test(8, search, Array({0, 1, 2, 3, 4, 5, 6, 7, expected_index}), expected_index); // General
  test(0, search, Array({expected_index, 9, 10, 11, 12}), expected_index); // General
  test(2, search, Array({4, 1, expected_index, 7, 10}), expected_index);  // General


  test(0, search, Array({expected_index, 1, expected_index, 7, 10}), expected_index); // General
  test(2, search, Array({2, 1, expected_index, 7, expected_index}), expected_index); // General

}

int main() {
    test_search();
    return 0;
}



