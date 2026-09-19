#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
    Why this is a tree-traversal question even though no tree is given

    Core idea:
    - Think of every board position as a node.
    - A valid knight move creates an edge between two nodes.
    - Therefore, the chessboard forms an implicit graph: we do not build it
      beforehand; we generate the neighbours of a position only when we visit it.
    - Starting from `src`, BFS explores this graph level by level. This exploration
      forms a tree whose root is `src`:
          level 0 -> positions reachable in 0 moves
          level 1 -> positions reachable in 1 move
          level 2 -> positions reachable in 2 moves, and so on
    - Hence, the first level at which we find `dest` is the minimum number of
      knight moves needed to reach it.

    Why BFS and not DFS?
    - Every knight move has the same cost: one move.
    - BFS completes all positions at distance `d` before exploring distance `d + 1`.
    - DFS may follow a long route first, so the first route it finds is not
      guaranteed to be the shortest one.

    Important graph detail:
    - The board itself is not actually a tree. The same position may be reached
      through several paths, and a knight can move back toward an older position.
    - `vis` prevents such repeated visits. A position is marked visited when it is
      inserted into the queue, so it can never be inserted again by another path.

    Implementation used below:
    1. Convert the given 1-based coordinates to 0-based coordinates.
    2. Store each position as `{row, column}` in a `pair<int, int>`.
    3. Push `src` into the queue. The marker `{-1, -1}` marks the end of one
       BFS level, so crossing it increments `step`.
    4. For every removed position, `explore` generates all 8 possible knight
       moves using the matching offsets in `x[]` and `y[]`.
    5. Ignore a generated position if it is outside the board or already visited.
    6. If a valid neighbour is `dest`, return the current `step`; otherwise,
       enqueue it for the next level.

    Small trace (using the question's 1-based coordinates):
        src = (1, 1), dest = (4, 4)

        level 0: (1, 1)
        level 1: (2, 3), (3, 2)
        level 2: (4, 4) can be reached from (2, 3)

        So the minimum number of moves is 2.

    Complexity:
    - There are at most n * n board positions, and each position checks 8 moves.
    - Time:  O(n^2)
    - Space: O(n^2) for the queue and visited matrix
*/

bool explore(pair<int, int>&front, pair<int, int>&dest, queue<pair<int,int>>&q, vector<vector<bool>> &vis, int &n) {
    int x[] = {-1, -1, 1, 1, 2, 2, -2, -2};
    int y[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for(int i=0; i<8; i++) {
        int newX = front.first + x[i];
        int newY = front.second + y[i];
        
        if(newX < 0 || newX >= n || newY < 0 || newY >= n || vis[newX][newY]) {
            continue;
        }

        if(make_pair(newX, newY) == dest) return true;
        
        q.push({newX, newY});
        vis[newX][newY] = true;
    }
    // I havent reached to destination
    return false;
}

int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
    
    // Convert to 0 based indexing
    pair<int, int>src = {knightPos[0] - 1, knightPos[1] - 1};
    pair<int, int>dest = {targetPos[0] - 1, targetPos[1] - 1};
    
    if(src == dest) return 0;
    
    queue<pair<int,int>>q;
    q.push(src);
    q.push({-1, -1});
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[src.first][src.second] = true;
    
    int step = 1;
    
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        
        if(front == make_pair(-1, -1)) {
            step++;
            if(!q.empty()) q.push({-1, -1});
        }
        else {
            if(explore(front, dest, q, vis, n)) return step;
        }
    }
    return -1;
}
