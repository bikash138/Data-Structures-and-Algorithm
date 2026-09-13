#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool findEven(int a) {
    return a % 2 == 0;
}

int main () {
    vector<int> arr;

    arr[0] = 10;
    arr[1] = 70;
    arr[2] = 30;
    arr[3] = 90;
    arr[4] = 60;
    arr[5] = 80;

    // Before the iterators will be the nnumbers which satisfies the funtion
    // After the iterator there will be the numbers which doesnt satisfies the number
    // Even the number on which the iterator is standing is falsy
    auto it = partition(arr.begin(), arr.begin(), findEven);

    for(int a: arr) {
        cout << a << " ";
    }
    
    return 0;
}