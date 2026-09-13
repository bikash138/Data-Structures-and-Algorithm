#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool findEven(int a) {
    return a % 2 == 0;
}

int main () {
    vector<int> arr;

    arr[0] = 1;
    arr[1] = 70;
    arr[2] = 30;
    arr[3] = 90;
    arr[4] = 60;
    arr[5] = 80;

    // It finds the first element that satisfies the condition
    auto it = find_if(arr.begin(), arr.end(), findEven);
    cout << *it << endl;
    
    return 0;
}