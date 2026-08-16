#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
We go row by row.
For each row, we try selecting every possible column.
Each recursive call selects one element from the current row
and moves to the next row.

The selected elements are added to `sum`.

When we have processed all rows (`row == mat.size()`),
we calculate the absolute difference between `target` and `sum`.

While returning from recursion, we take the minimum
difference among all possible choices.
*/

int solve(vector<vector<int>>& mat,int target, int sum, int row) {
    /*
    Base Case:
    When the last row processing is done then simply return the difference of target and sum 
    */ 
    if(row == mat.size()) {
        return abs(target - sum);
    }
    
    int ans = INT_MAX;
    // This loop will iterate over each column on every row
    for(int col=0; col<mat[row].size(); col++) {
        // On every recursive call add the element into the sum and increase the row number
        int recAns = solve(mat, target, sum+mat[row][col], row+1);
        // While creating answer we need the minimum absolute difference
        ans = min(ans, recAns);
    }
    return ans;
}

int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    int sum = 0, row = 0;
    return solve(mat, target, sum, row);
}