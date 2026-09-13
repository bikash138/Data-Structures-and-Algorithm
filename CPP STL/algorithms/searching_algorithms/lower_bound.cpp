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

    int target = 40;

    // IF target is found then it will return greater than equal to target.
    auto it = lower_bound(arr.begin(), arr.end(), target);
    cout << *it << endl;

    // It will always return greater than target
    auto it = upper_bound(arr.begin(), arr.end(), target);
    cout << *it << endl;
    
    return 0;
}