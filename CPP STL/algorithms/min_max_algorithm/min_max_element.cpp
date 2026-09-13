#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    vector<int> arr;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[2] = 40;
    arr[2] = 50;

    auto it1 = min_element(arr.begin(), arr.end());
    auto it2 = max_element(arr.begin(), arr.end());
    cout << *it1 << endl;
    cout << *it2 << endl;
    
    return 0;
}