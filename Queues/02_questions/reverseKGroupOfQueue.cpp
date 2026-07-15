#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseInKGroup(queue<int> &q, int k, int unusedELmentCount) {
    // First we need to find out:
    // Do we we have k elements to reverse
    if(unusedELmentCount >= k) {
        // If yes then use stack to reverse it
        stack<int> st;
        for(int i=0; i<k; i++) {
            // Push the  1st k in the stack
            int element = q.front();
            q.pop();
            st.push(element);
        }

        for(int i=0; i<k; i++){
            // Pop the elements from the stack to get reversed value
            int element = st.top();
            st.pop();
            q.push(element);
        }

        //Now we handled one case else will be handled by recursion
        reverseInKGroup(q, k, unusedELmentCount - k);
    }
    // Dont have the group
    else{
        // Push all the elments as it is
        for(int i=0; i<unusedELmentCount; i++) {
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
}

// T.C -> We have accessed each element two time
// First while pushing in the stack
// Second while pushing the reversed groups back in the queue 
// So O(2n) = O(n)