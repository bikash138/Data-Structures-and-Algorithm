#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
    Selection Sort divides the array into two parts:
    - A sorted part on the left.
    - An unsorted part on the right.

    During each pass, we search the unsorted part for its smallest element.
    We then swap that element with the first element of the unsorted part.
    This grows the sorted part by one element after every pass.

    Example:
    5 | 3 | 4 | 1

    Pass 1: i = 0
    The smallest element from index 0 to 3 is 1.
    Swap 5 and 1:
    1 | 3 | 4 | 5

    Pass 2: i = 1
    The smallest element from index 1 to 3 is 3.
    It is already in the correct position:
    1 | 3 | 4 | 5

    Pass 3: i = 2
    The smallest element from index 2 to 3 is 4.
    It is already in the correct position:
    1 | 3 | 4 | 5

    The outer loop runs n - 1 times because once the first n - 1 elements are
    placed correctly, the final element must also be in its correct position.

    The inner loop starts at i + 1 because minIndex initially points to i.
    It examines the remaining unsorted elements and updates minIndex whenever
    it finds a smaller element.

    Unlike Bubble Sort, Selection Sort performs at most one swap per pass.

    Time complexity:
    - Best case:    O(n^2)
    - Average case: O(n^2)
    - Worst case:   O(n^2)

    Space complexity: O(1)
*/

void slectionSort (vector<int> &v) {
    int n = v.size();

    for(int i=0; i<n-1; i++) {
        // Assume the first unsorted element is the smallest.
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(v[j] < v[minIndex]) {
                // Store the index of the new smallest element.
                minIndex = j;
            }
        }
        // Place the smallest unsorted element at index i.
        swap(v[i], v[minIndex]);
    }
}
