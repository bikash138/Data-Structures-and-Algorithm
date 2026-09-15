#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
    Bubble Sort repeatedly compares adjacent elements.
    If the left element is greater than the right element, they are swapped.

    Example (first pass):
    5 | 4 | 3 | 2 | 1
    4 | 5 | 3 | 2 | 1
    4 | 3 | 5 | 2 | 1
    4 | 3 | 2 | 5 | 1
    4 | 3 | 2 | 1 | 5

    After one complete pass, the largest unsorted element has "bubbled up"
    to its correct position at the end of the unsorted part.

    For n elements, at most n - 1 passes are needed:
    - The outer loop counts the passes.
    - The inner loop compares v[j] with its neighbor v[j + 1].
    - The inner loop stops at n - i - 1 because:
        1. j + 1 must remain a valid index.
        2. The last i elements are already in their correct positions.

    Therefore, each new pass performs one fewer comparison than the previous
    pass. After all passes, the array is sorted in ascending order.

    Time complexity:  O(n^2)
    Space complexity: O(1)
*/

void bubbleSort (vector<int> &v) {
    int n = v.size();

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}
