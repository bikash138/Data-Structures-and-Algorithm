#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

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