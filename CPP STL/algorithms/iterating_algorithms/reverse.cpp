#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    vector<int> arr;

    arr[0] = 1;
    arr[1] = 70;
    arr[2] = 30;
    arr[3] = 90;
    arr[4] = 60;
    arr[5] = 80;

    reverse(arr.begin(), arr.end());

    for(int a: arr) {
        cout << a << " ";
    }
    
    return 0;
}