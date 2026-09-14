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

    // It converts the vector into a max heap
    make_heap(arr.begin(), arr.end());
    // Make sure to push any element in the vector before heap creation

    //deletion: It shifts the max element in the last index
    pop_heap(arr.begin(), arr.end());
    arr.pop_back();

    // sorting of the heap
    sort_heap(arr.begin(), arr.end());

    for(int a: arr) {
        cout << a << " ";
    }
    
    return 0;
}