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

    // It shift the elements 3 indexes ahead
    rotate(arr.begin(), arr.begin() + 3, arr.end());

    for(int a: arr) {
        cout << a << " ";
    }
    
    return 0;
}