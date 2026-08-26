#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:

    int solve(vector<vector<int>>& triangle, int row, int col) {
        // If we reached the last row then simply return the current item
        // As we cannot move further
        if(row == triangle.size() - 1) return triangle[row][col];

        // For the ith element we will increment the row and keep the same col
        int down = triangle[row][col] + solve(triangle, row + 1, col);
        // For the i+1th element we will increment the row as well as col
        int cross = triangle[row][col] + solve(triangle, row + 1, col + 1);

        // As we want the minimum of both the numbers we will return the 
        return min(down, cross);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = 0, col = 0;
        return solve(triangle, row, col);
    }
};

// T.C -> 2^n