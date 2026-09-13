#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    vector<int> arr;

    arr[0] = 10;
    arr[1] = 70;
    arr[2] = 30;
    arr[3] = 90;
    arr[4] = 60;
    arr[5] = 80;

    // Unique removes the duplicate elements in the container
    // It returns a iterator before which there are all unique elements
    // After the iterators there will be all duplciate elements
    auto it = unique(arr.begin(), arr.begin() + 3, arr.end());
    
    // we can remove the duplicates using erase funtion
    arr.erase(it, arr.end());

    for(int a: arr) {
        cout << a << " ";
    }
    
    return 0;
}