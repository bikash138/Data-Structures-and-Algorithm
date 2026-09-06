#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans;

    while(s <= e) {
        if(arr[mid] < arr[mid+1]) {
            // If we mid < mid+1 then this is ihe increasing line 
            s = mid + 1;
        }
        else {
            // If it is greater then it might be the answer 
            // therefore store it and move
            ans = mid;
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}