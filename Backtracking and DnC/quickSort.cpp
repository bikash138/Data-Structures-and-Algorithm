#include<iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
    Quick Sort is a algorithm where:
    - We set a pivot 
    - We need to place the pivot in such a way such that the 
      element on the right of pivot > the elements on the left

    So for this:
    - We will always make the last element of the array as pivot
    - We will keep two pointers i and j.
    - i will be kept at index = start-1 and j at index = start
    - NOw if arr[j] > arr[pivot] then simply increment j and do nothing
    - Id arr[j] < arr[pivot] then increment i and swap arr[i] with arr[j] ans incremnet j
    - Doing this if we reach the pivot i.e. the last index then increment i and swap the arr[pivot] with arr[i]
    - Now if we see the pivot is palced in the right position 
      where the left numbers is small while right section islarger
    - Now do the same thing again recursvely for the right partiotion and left partion
*/

void quickSort(int arr[], int start, int end) {
    // we will keep partioning till it reaches single element
    if(start >= end) return;

    // Initilaise the variables
    int pivot = end;
    int i = start - 1;
    int j = start;

    // 
    while(j < pivot) {
        if(arr[j] < arr[pivot]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i-1);
    quickSort(arr, i+1, end);
}

// T.C -> O(n^2) and in average case O(n log n)