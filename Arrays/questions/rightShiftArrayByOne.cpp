#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rightShift(vector<int> arr) {
    int size = arr.size();
    int lastElement = arr[size-1];

    for(int i=size-1; i>=0; i--) {
        if(i != 0) {
            arr[i] = arr[i-1];
        }
        else {
            arr[0] = lastElement;
        }
    }
}