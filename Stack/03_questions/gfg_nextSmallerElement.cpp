#include<stack>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
PROBLEM: Next Smaller Element
For every element in the array, find the first element to its RIGHT that is
smaller than it. If no such element exists, the answer is -1.

--------------------------------------------------------------------------
BRUTE FORCE APPROACH
- Stand at each element and scan all the elements to its right.
- The moment a smaller element is found, that is the answer; otherwise -1.
- Problem: every element is compared many times. For example, the last
  element ends up being checked against almost n-1 elements.
- Time Complexity: O(n^2)

--------------------------------------------------------------------------
OPTIMAL APPROACH (using a stack, traversing RIGHT -> LEFT)

Key idea:
- The last element always answers -1, because nothing sits to its right.
- We traverse from right to left and keep a stack of "candidates" that
  could be the next smaller element for elements we are yet to visit.
- Why right to left? Because the current element might itself be the next
  smaller element of some element that comes before it (to its left).

Algorithm (for the current element while moving right -> left):
1. Pop from the stack while the top is >= current element.
   (Those tops can never be a "smaller" answer, so they are useless.)
2. After popping, the answer for the current element is:
   - st.top()  if the stack is not empty (this is the nearest smaller), or
   - -1        if the stack is empty.
3. Push the current element onto the stack, since it becomes a candidate
   for the elements still on its left.

Time Complexity : O(n)  (each element is pushed and popped at most once)
Space Complexity: O(n)  (the stack)

--------------------------------------------------------------------------
EXAMPLE

    arr = [4, 8, 5, 2, 25]
    answer array (same size), filled from right to left.

    i = 4  val = 25 : stack empty            -> ans = -1, push 25   stack:[25]
    i = 3  val = 2  : top 25 >= 2, pop        -> stack empty
                      stack empty             -> ans = -1, push 2    stack:[2]
    i = 2  val = 5  : top 2 < 5, keep          -> ans = 2,  push 5    stack:[2,5]
    i = 1  val = 8  : top 5 < 8, keep          -> ans = 5,  push 8    stack:[2,5,8]
    i = 0  val = 4  : top 8 >= 4, pop; top 5 >= 4, pop; top 2 < 4, keep
                                              -> ans = 2,  push 4    stack:[2,4]

    RESULT: [2, 5, 2, -1, -1]
*/


vector<int> nextSmallerElement(vector<int> arr) {
    int size = arr.size();
    vector<int> ans(size);
    stack<int> st;

    st.push(-1);

    for(int i=size-1; i>=0; i--) {
        while(arr[i] <= st.top()){
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};

    cout << "Input : ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    vector<int> ans = nextSmallerElement(arr);

    cout << "Output: ";
    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}