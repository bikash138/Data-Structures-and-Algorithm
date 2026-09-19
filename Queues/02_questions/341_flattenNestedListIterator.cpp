#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
    NestedInteger is itself is a data structure class
    so to access the integer or the nested array of this class
    we need to use some methods which is already mentioned in the question
    
    So ust remeber not to use item directly rather use item.isInteger, 
    item.getInteger and item.getList methods
*/

class NestedIterator {
    queue<int> flattenQ;

    void flatten(vector<NestedInteger> &nestedList) {
        for(auto item:nestedList) {
            if(item.isInteger()) flattenQ.push(item.getInteger());
            else flatten(item.getList());
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        int front = flattenQ.front();
        flattenQ.pop();
        return front;
    }
    
    bool hasNext() {
        return !flattenQ.empty();
    }
};