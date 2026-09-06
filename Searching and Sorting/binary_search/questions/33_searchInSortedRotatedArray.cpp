#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if(target == nums[mid]) return mid;

        // Handle the left sorted part
        if(nums[s] <= nums[mid]) {
            // Check if the target is in this sorted list
            if(nums[s] <= target && target < nums[mid]){
                e = mid - 1;
            }
            else s = mid + 1;
        }

        // RIght half is sorted: mid crossed the rotation point
        else {
            // Check if the target is in this sorted list
            if(nums[mid] < target && target <= nums[e]){
                s = mid + 1;
            }
            else e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return -1;
}