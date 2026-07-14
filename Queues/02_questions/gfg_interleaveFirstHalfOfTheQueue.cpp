#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Interleave the first half of a queue with the second half.
// [1,2,3,4,5,6] -> [1,4,2,5,3,6]
//
// A queue behaves like a conveyor belt: popping the front and immediately
// pushing it back sends that element around one lap, so it ends up last in
// line. That single move is what lets us interleave in place.
//
//   after splitting:  f = [1,2,3]      q = [4,5,6]
//
//   push 1 -> q = [4,5,6,1]      rotate 4 -> q = [5,6,1,4]
//   push 2 -> q = [5,6,1,4,2]    rotate 5 -> q = [6,1,4,2,5]
//   push 3 -> q = [6,1,4,2,5,3]  rotate 6 -> q = [1,4,2,5,3,6]
//
// The front of q is always the next unused second-half element, so rotating
// it lands it directly behind the element we just pushed. By the time f is
// empty, everything has cycled around exactly once and is interleaved.
//
// Only works when both halves are the same length (size must be even).
void rearrange(queue<int> &q) {
    queue<int> f;
    int size = q.size();

    // Move the first half into the helper queue, leaving the second half in q.
    for(int i=0; i<size/2; i++) {
        f.push(q.front());
        q.pop();
    }

    for(int i=0; i<size/2; i++) {
        // Append the next first-half element.
        q.push(f.front());
        f.pop();
        // Send q's current front around to the back, right behind it.
        q.push(q.front());
        q.pop();
    }
}