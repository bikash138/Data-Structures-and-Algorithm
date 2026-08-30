#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>> & board) {
    /*For a cell to be safe not all 8 direction needs to be checked
        Because queen do not have danger from:
        1. The column right to it i.e next column as there is no queen
        2. Top and Bottom because it is the same columns the queen is placed
        Hence we need to check the left horizontal cells and top/bottom left cells
    */

    int n = board.size();
    // We need to check 3 directions

    // LEFT Horizontal
    for(int i=0; i<=col; i++) {
        if(board[row][i] == 'Q') {
            // There is a queen in the same row hence attack will happen
            return false;
        }
    }

    // Upper Diagonal
    int i = row - 1;
    int j = col - 1;
    while(i >= 0 && j >= 0 ) {
        if(board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }

    // Bottom Diagonal
    int x = row + 1;
    int y = col - 1;
    while(x < n && y >= 0 ) {
        if(board[x][y] == 'Q') {
            return false;
        }
        x++;
        y--;
    }
    // If all the checks has been passed then the position is safe
    return true;
}

// OPTIMISED WAY TO KNOW ISSAFE
unordered_map<int, bool> leftHorizontalCheck;
unordered_map<int, bool> upperDiagonalCheck;
unordered_map<int, bool> bottomDiagonalCheck;

bool isSafe(vector<vector<char>> &board, int row, int col, int n) {

    // While occupying the cell we will keep the position marked as true because
    // Left Horizontal -> Has same row number
    // Upper Diagonal -> Has the same difference between row and col. Ex: 1,1 = 0; 2,2 = 0
    // Lower Diagonal -> Has the same sum between row and col. Ex: 1,2 = 3; 2,1 = 3

    if(leftHorizontalCheck[row] == true) {
        return false;
    }
    if(upperDiagonalCheck[row-col] == true) {
        return false;
    }
    if(bottomDiagonalCheck[row+col] == true) {
        return false;
    }

    return true;
}

void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int n) {
    vector<string> temp;

    for(int row=0; row < n; row++) {
        string output = "";
        for(int col=0; col<n; col++) {
            char ch = board[row][col];
            output.push_back(ch);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}


void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int n, int col) {
    // Base Case: As we are trvelling column wise hence it should be in limit
    if(col >= n) {
        // If we reach the last column, it means we got our answer
        storeSolution(board, ans, n);
        return;
    }

    // 1 Case
    for(int row=0; row<n; row++) {
        if(isSafe(row, col, board)) {
            board[row][col] = 'Q';
            // As we are placing the queens columnwise
            // Therefore we are incrementing the colum by 1
            solve(board, ans, n, col+1);
            // Backtracking: If solution not found
            // Then while coming back mark the cell as empty
            board[row][col] = '.';
        }
    }
}

// OPTIMISED WAY USING MAP
void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int col, int n) {
    // Base Case: While iterating if we go put of the column
    if( col >= n ) {
        storeSolution(board, ans, n);
        return;
    }

    // We need to move
    for(int row = 0; row < n; row++){
        if(isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            // While placing the queen, we should mark the positions as true
            leftHorizontalCheck[row] = true;
            upperDiagonalCheck[row-col] = true;
            bottomDiagonalCheck[row+col] = true;
            solve(board, ans, col+1, n);

            //Bactracking
            board[row][col] = '.';
            // While coming back we should mark the positions back to false
            leftHorizontalCheck[row] = false;
            upperDiagonalCheck[row-col] = false;
            bottomDiagonalCheck[row+col] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    // Create the board of size n for travelling
    vector<vector<char>> board (n, vector<char>(n, '.'));
    // Starting with column = 0
    int col = 0;

    solve(board, ans, n, col);
    return ans;

}