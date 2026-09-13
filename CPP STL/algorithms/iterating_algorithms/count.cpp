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
    arr[3] = 30;
    arr[4] = 60;
    arr[5] = 30;

    // count
    int target = 30;
    int ans = count(arr.begin(), arr.end(), target);
    cout << ans << endl;

    // count_if
    int ansIf = count_if(arr.begin(), arr.end(), findEven);
    cout << ansIf << endl;
    
    return 0;
}