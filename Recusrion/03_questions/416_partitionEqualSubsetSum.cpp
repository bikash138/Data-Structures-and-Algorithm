#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

bool solve(vector<int> &nums, int target, int index) {
    //Base Case
    // While making recursive calls if target becomes negative that means sum was not possible
    // Make sure to keep the track of index, so that it should not try to access the invalid index 
    if(target < 0 || index == nums.size()) return false;
    if(target == 0) return true;
    
    // While including subtract the current element for the next call
    bool include = solve(nums, target - nums[index], index+1);
    bool exclude = solve(nums, target, index+1);

    // As we want only one successfull case hence we OR them
    return include || exclude;
}

bool canPartition(vector<int>& nums) {
    int size = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    /*
    If the sum of the elements in the array is even 
    then only we can divide it into two parts otherwise not possible
    */
    if(sum & 1) return false;

    int target = sum/2;

    // Index for the include-exclude pattern
    int index = 0;

    int ans = solve(nums, target, index);
}