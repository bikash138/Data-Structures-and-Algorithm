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

    bool ans = binary_search(arr.begin(), arr.end(), target);
    cout << ans << endl;
    
    return 0;
}