#include <iostream>
#include <stdlib.h>
#include <stddef.h>
#include <vector>

using namespace std;

template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    for(auto& x : v) {
        o << x << ", ";
    }
    return o << "]";
}


int SearchElement(vector<int>& array, const int key) {
    size_t i = 0;
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
        cerr << "failed: f(" << p1 << ", " << p2 << ")" << endl;
        cerr << "Expected: " << expected << endl;
        cerr << "Actual: " << got << endl;
    }

}


template <class TFunc, class TResult, class TParam1>
void test(TResult expected ,TFunc f, TParam1 p1) {
    auto got = f(p1);
    if (got != expected) {
        cerr << "failed: f(" << p1 << ")" << endl;
        cerr << "Expected: " << expected << endl;
        cerr << "Actual: " << got << endl;
    }

}

void test_search() {
typedef vector<int> Array;
    test(6, SearchElement, Array({0, 1, 2, 3, 4, 5, 6, 7, 8}), 8);
}

int main() {
    test_search();
    return 0;
}



