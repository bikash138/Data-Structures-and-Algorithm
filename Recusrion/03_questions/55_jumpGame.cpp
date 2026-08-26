#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

bool solve(vector<int>& nums, int index) {
    // If we reached the last index after the jumps then we found the path hence return true
    if(index == nums.size() - 1) return true;
    // If the jump has made us land on the out of bound index then return false
    if(index >= nums.size()) return false;
    // If we get 0 at any position then further jump not possible hence return false
    // But 0 is okay at last index which gets covered in the first condition
    if(nums[index] == 0) return false;

    bool recAns = false;
    // We need to iterate on all possible types of jumps hence we used loops
    for(int jump = 1; jump <= nums[index]; jump++) {
        // Now call the function recursively and update the index on each call
        recAns = recAns || solve(nums, index + jump);
    }
    return recAns;
}

bool canJump(vector<int>& nums) {
    return solve(nums, 0);
}
