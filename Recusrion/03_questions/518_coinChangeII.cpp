#include<iostream>
#include <vector>
using namespace std;

int solve(int amount, int index, vector<int> &coins) {
    //base case
    if(amount == 0) {
        // If amount becomes 0 it means we get one way to make the amount
        return 1;
    }
    if(index >= coins.size()) {
        // If the index passed the array length then there is no way
        return 0;
    }

    // Include the current coin and find the number of ways

    // Include only if it is less than equals amount because 4 cannot be created using coin of 5
    int includeKaAns = 0;
    if(coins[index] <= amount) {
        // Subtract the coin from the amount while including the coin
        // Index will remain same because the coin can be resued again
        includeKaAns = solve(amount-coins[index], index, coins);
    }
    // Exclude the current coin
    // Keep the amount same but increase the index
    int excludeKaAns = solve(amount, index+1, coins);
    // total ways 
    int total = includeKaAns + excludeKaAns;

    return total;
}

int change(int amount, vector<int>& coins) {
    int index = 0;
    int ans = solve(amount, index, coins);
    return ans;
}