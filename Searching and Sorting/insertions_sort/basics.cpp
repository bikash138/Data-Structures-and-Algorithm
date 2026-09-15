#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
    Insertion Sort divides the array into two parts:
    - A sorted part on the left.
    - An unsorted part on the right.

    We take the first element from the unsorted part and store it as the key.
    Then, we compare the key with the elements before it. Every element greater
    than the key is shifted one position to the right. The key is inserted into
    the empty position that remains.

    Example:
    5 | 3 | 4 | 1

    Pass 1: key = 3
    Shift 5 to the right and insert 3 before it:
    3 | 5 | 4 | 1

    Pass 2: key = 4
    Shift 5 to the right and insert 4 after 3:
    3 | 4 | 5 | 1

    Pass 3: key = 1
    Shift 5, 4, and 3 to the right, and insert 1 at the beginning:
    1 | 3 | 4 | 5

    The outer loop starts at i = 1 because the element at index 0 is already
    considered sorted. At the beginning of every pass, the elements from index
    0 to i - 1 are sorted.

    The while loop moves backward through the sorted part until:
    - It reaches the beginning of the array, or
    - It finds an element that is less than or equal to the key.

    Time complexity:
    - Best case:    O(n), when the array is already sorted.
    - Average case: O(n^2)
    - Worst case:   O(n^2), when the array is sorted in reverse order.

    Space complexity: O(1)
*/

void insertionSort(vector<int> &v) {
    int n = v.size();

    // Index 0 is treated as a sorted subarray containing one element.
    for (int i=1; i<n; i++) {
        int key = v[i];
        int j = i-1;

        // Shift larger elements one position to the right.
        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        // Insert the key after the last element that is less than or equal to it.
        v[j+1] = key;
    }
}
