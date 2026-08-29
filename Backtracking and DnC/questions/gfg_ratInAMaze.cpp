#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(vector<vector<int>>& maze, int row, int col, int newX, int newY) {
    // newX and newY should be valid cell and the cell should be unvisited
    if((newX >= 0 && newX < row) && (newY >=0 && newY < col) && maze[newX][newY] == 1){
        return true;
    } else {
        return false;
    }
}

void solve(vector<vector<int>>& maze, int row, int col, int srcX, int srcY, int destX, int destY, string output, vector<string> &ans) {
    // Base Case -> If current pos == dest pos => answer is ready
    if(srcX == destX && srcY == destY) {
        // We arrived at destination
        ans.push_back(output);
        return;
    }
    
    // First case needs to be solved
    // So first case is the movement which the rat can make
    // It can be of four types i.e. Up, Down, Right, Left
    
    int newX;
    int newY;
    
    // UP
    newX = srcX - 1;
    newY = srcY;
    if(isSafe(maze, row, col, newX, newY)) {
        maze[newX][newY] = 0;
        // Rest will be handled by recursion
        solve(maze, row, col, newX, newY, destX, destY, output + 'U', ans);
        
        //Backtracking: While coming back we need to make the cell unvisited
        maze[newX][newY] = 1;
    }

    // DOWN
    newX = srcX + 1;
    newY = srcY;
    
    if(isSafe(maze, row, col, newX, newY)) {
        maze[newX][newY] = 0;
        // Rest willbe handled by recursion
        solve(maze, row, col, newX, newY, destX, destY, output + 'D', ans);
        
        //Backtracking: While coming back we need to make the cell unvisited
        maze[newX][newY] = 1;
    }
    
    // RIGHT
    newX = srcX;
    newY = srcY + 1;
    
    if(isSafe(maze, row, col, newX, newY)) {
        maze[newX][newY] = 0;
        // Rest willbe handled by recursion
        solve(maze, row, col, newX, newY, destX, destY, output + 'R', ans);
        
        //Backtracking: While coming back we need to make the cell unvisited
        maze[newX][newY] = 1;
    }
    
    // LEFT
    newX = srcX;
    newY = srcY - 1;
    
    if(isSafe(maze, row, col, newX, newY)) {
        maze[newX][newY] = 0;
        // Rest willbe handled by recursion
        solve(maze, row, col, newX, newY, destX, destY, output + 'L', ans);
        
        //Backtracking: While coming back we need to make the cell unvisited
        maze[newX][newY] = 1;
    }
    
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    // code here
    int row = maze.size();
    int col = maze[0].size();


    // Check if the the destination and source is valid or not
    if (maze[0][0] == 0 || maze[row - 1][col - 1] == 0) {
        return {};
    }
    
    int srcX = 0;
    int srcY = 0;
    
    int destX = row-1;
    int destY = col-1;
    
    string output = "";
    
    vector<string> ans;

    // Before moving mark the source as visited
    maze[0][0] = 0;
    
    solve(maze, row, col, srcX, srcY, destX, destY, output, ans);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}