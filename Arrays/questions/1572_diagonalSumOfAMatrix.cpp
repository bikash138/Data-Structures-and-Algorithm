#include<iostream>
#include <vector>
#include <numeric>
using namespace std;


int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();

    int sum = 0;
    for(int i=0; i<n; i++) {
        // Below represents the primary diagonal
        sum += mat[i][i];
        // Below represents the secodary diagonal
        sum += mat[i][n-i-1];
    }

    // If the metrix is odd then middle element needs to removed once 
    if( n & 1 ) {
        sum -= mat[n/2][n/2];
    }

    return sum;
}