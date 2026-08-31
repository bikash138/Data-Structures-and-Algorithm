#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n-1;
    int endingCol = m-1;

    vector<int> ans;

    // If there are any pending elements to print
    // Then -> 4 steps -> startingRow -> endingCol -> endingRow -> startingCol

    while(startingRow <= endingRow && startingCol <= endingCol) {
        // startingRow
        for(int col = startingCol; col <= endingCol; col++) {
            ans.push_back(matrix[startingRow][col]);
        }

        startingRow++;

        // endingCol
        for(int row = startingRow; row <= endingRow; row++) {
            ans.push_back(matrix[row][endingCol]);
        }

        endingCol--;
        
        // endingRow

        /*
            We are checking the condition again here for right -> left
            and bottom -> top trversal becasue it might happen the above 
            operations made the startingRow and startingCol cross the 
            vector sizes inside teh sequential loop therefore again we need
            to check it conditions.
        */
        if(startingRow <= endingRow) {
                for(int col = endingCol; col >= startingCol; col--) {
                ans.push_back(matrix[endingRow][col]);
            }

            endingRow--;
        }
        // startingCol
        if(startingCol <= endingCol) {
                for(int row = endingRow; row >= startingRow; row--) {
                ans.push_back(matrix[row][startingCol]);
            }

            startingCol++;
        } 
    }

    return ans;
}