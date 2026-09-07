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
            // s = mid + 1;
            /* 
            This can be oprtimised as in the same iteration we had 
            checked mid+1 for the target in the above code so we can 
            directly move to mid+2
            */
            s = mid + 2;
        }
        else {
            // e = mid - 1;
            /* 
            This can also be optimised as in the same iteration we had 
            checked mid-1 for the target in the above code so we can 
            directly move to mid-2
            */
           e = mid - 2;
        }
    }
    return -1;
}