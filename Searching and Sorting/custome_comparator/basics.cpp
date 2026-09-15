#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool mycomp(int &a, int &b) {
    // increasing order
    return a < b;
}

int main () {
    vector<int> v = {10, 9, 90, 30, 15, 95};

    sort(v.begin(), v.end(), mycomp);
}