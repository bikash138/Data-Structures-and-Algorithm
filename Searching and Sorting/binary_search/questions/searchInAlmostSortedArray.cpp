#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int findTarget(vector<int>& arr, int target) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    
    while (s <= e ) {
        int mid = s + (e-s) / 2;
        
        // In addition of checking mid here we need to check mid+1 and mid-1 as well
        // eveything else remains same
        if(arr[mid] == target) return mid;
        if(arr[mid - 1] == target) return mid-1;
        if(arr[mid + 1] == target) return mid+1;
        
        if(target > arr[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return -1;
}