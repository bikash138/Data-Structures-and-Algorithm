#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printDouble(int a) {
    cout << 2*a << endl;
}

int main () {
    vector<int> arr;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    arr[5] = 60;

    // It takes range of the numbers and the funtion to apply
    for_each(arr.begin(), arr.end(), printDouble);
    
    return 0;
}