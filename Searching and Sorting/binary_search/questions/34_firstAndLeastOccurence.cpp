#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int firstOccurence(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e - s) / 2;
    int firstOccurence = -1;

    while (s <= e) {
        if( target == nums[mid] ) {
            firstOccurence = mid;
            e = mid - 1;
        }
        else if ( target > nums[mid] ) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return firstOccurence;
}

int lastOccurence(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e - s) / 2;
    int lastOccurence = -1;

    while (s <= e) {
        if( target == nums[mid] ) {
            lastOccurence = mid;
            s = mid + 1;
        }
        else if ( target > nums[mid] ) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return lastOccurence;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    int index1 = firstOccurence(nums, target);
    int index2 = lastOccurence(nums, target);
    ans.push_back(index1);
    ans.push_back(index2);
    return ans;
}