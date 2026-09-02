#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
 So for this question we need to follow the following algorithms:
 1. First we will travel in all three direction
 2. If we find any square while exploring then we will return that
 3. So while exploring if any of the direction returns 0 then square can't be formed
 4. IF not then simply add 1 and return it.
 5. At the end we need the maximum of returned squres because 
    the square could have formed anywhere in the whole matrix.
*/
int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi) {
    // Base Case: Out of bound index will return 0 sized square
    if(i >= row || j >= col) return 0;

    // Being standing on a position we have three direction to move
    // right
    int right = solve(matrix, i, j+1, row, col, maxi);
    // left
    int diagonal = solve(matrix, i+1, j+1, row, col, maxi);
    // down
    int down = solve(matrix, i+1, j, row, col, maxi);

    // NOw we need to check whether a square can be created on the current postion or not
    // 1 sized matrix can be created if '1' is found
    if(matrix[i][j] == '1') {
        // We have added 1 to consider the small square of
        // size 1 which is getting created on which cell we are standing
        int ans = 1 + min(right, min(down, diagonal));
        // Finally we need the max of all the squares being created
        maxi = max(maxi, ans);
        return ans;
    }
    else {
        // If we are standing at 0 then square cannot be formed including current postiion
        // Hence return 0
        return 0;
    }
}

int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    int i = 0;
    int j = 0;

    int maxi = 0;

    solve(matrix, i, j, row, col, maxi);

    // Area of the largest square
    return maxi*maxi;
}