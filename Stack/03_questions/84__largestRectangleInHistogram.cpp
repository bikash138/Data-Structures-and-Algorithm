#include<stack>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &heights) {
    int size = heights.size();
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);

    for(int i=size-1; i>=0; i--) {
        int element = heights[i];

        while(st.top() != -1 && heights[st.top()] > element){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr) {
    int size = arr.size();
    vector<int> ans;
    stack<int> st;

    st.push(-1);

    for(int i=0; i<size; i++) {
        while(arr[i] <= st.top()){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(arr[i]);
    }
    return ans;  
}


int largestRectangleArea(vector<int> &heights) {

}