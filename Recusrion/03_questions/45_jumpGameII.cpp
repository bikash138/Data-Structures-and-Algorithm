#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

// BASIC FLOW IS SAME AS JUMP GAME 1

bool solve(vector<int>& nums, int index, int &ans, int step) {
    // When we reached the true base case
    // Save the minimum of answer
    if(index == nums.size() - 1) {
        ans = min(ans, step);
    }
    if(index >= nums.size()) return false;
    if(nums[index] == 0) return false;

    bool recAns = false;
    for(int jump = 1; jump <= nums[index]; jump++) {
        // Now call the function recursively and update the index on each call
        // For each iteration increase the step by 1 because nums[index] is not the actual step
        // Rather the number of times we are reaching the destination is the actual step
        recAns = recAns || solve(nums, index + jump, ans, step + 1);
    }
    return recAns;
}

int jump(vector<int>& nums) {
    int ans = INT_MAX;
    int index = 0;
    int step = 0;
    solve(nums, 0, ans, step);
    return ans;
}