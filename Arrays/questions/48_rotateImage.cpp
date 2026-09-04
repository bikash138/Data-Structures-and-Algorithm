#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    // We will only swap the the second half of the matrix
    // As it is a square matrix it will work
    // For non square matrix we would have to create a new matrix
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Row wise reverse
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end()); 
    }

}