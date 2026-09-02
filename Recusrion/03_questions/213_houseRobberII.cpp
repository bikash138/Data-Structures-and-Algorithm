#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
    THe logic is simple,
    As the question says that the while choosing the first house 
    we cannot rob the last house which sound something like circular house arrangement

    So we can simply call the house robber I funtion but for the first time when we include
    1st house then we need to exclude the last house 
    On the other hand if we include the last house we need to drop the first house.

    Therefore we will call the solve() funtion recursively first from 0 -> size-2 index
    and another call will be made from 1 -> size-1 index
*/

// This code is same as the house robber
int solve(vector<int>& nums, int index, int size) {
    if(index >= size) {
        return 0;
    }

    // Include the first house
    int option1 = nums[index] + solve(nums, index+2, size);
    // Exclude the second house
    int option2 = 0 + solve(nums, index+1, size);

    int finalAns = max(option1, option2);
    return finalAns;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0]; // <---Yeh mai bhul gaya tha
    }
    // For the first case we will go from 0 -> n-2 index because
    // the first house cannot rob the last house 
    // All the code in the solve question is using n as the size
    // That means 0 to n-1 index refers to n
    // So for 0 to n-2 index will refer to n-1 here
    int robWithoutLastHouse = solve(nums, 0, n-1);

    // The last house cannot rob the first house 
    // hence it will go from 1 -> n-1
    // which means for the solve funtion it will be 1 to n
    int robWithLastHouse = solve(nums, 1, n);

    // We want max of both
    int ans = max(robWithoutLastHouse, robWithLastHouse);
    return ans;
    
}