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
void test(TResult expected ,TFunc f, TParam1 parameters, TParam2 value) {
    auto got = f(parameters);
    if (got != expected) {
        cerr << "failed" << endl;
        cerr << "Expected: " << expected << endl;
        cerr << "Actual: " << got << endl;
    }

}


template <class TFunc, class TResult, class TParam1>
void test(TResult expected ,TFunc f, TParam1 parameters) {
    auto got = f(parameters);
    if (got != expected) {
        cerr << "failed" << endl;
        cerr << "Expected: " << expected << endl;
        cerr << "Actual: " << got << endl;
    }

}

void test_search() {
typedef vector<int> Array;
    test(8, SearchElement, Array({0, 1, 2, 3, 4, 5, 6, 7, 8}), 8);
}

int main() {
    test_search();
    return 0;
}



