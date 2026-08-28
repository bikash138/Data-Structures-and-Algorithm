/*
This sorting alogirthm is very interesting where:
- The array is first broken into two halves until it reaches upto single element
- Now we all know an array which has only 1 element is already sorted
- Now we can use the algorithmn of merging two sorted arrays
- We will start merging all the sorted arrays which were broken into two halves
- At the end we will get our final answer as a sorted array

So in this algorithm we will be using two funtions:
- First two divide the array into halves
- Another to merge those array to build the sorted one

T.C -> O(n log n)
*/

#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

void merge(int arr[], int s, int e, int mid) {
    // Get the length of both arrays to merge
    int leftArrayLength = mid - s + 1;
    int rightArrayLength = e - mid;

    int *arr1 = new int[leftArrayLength];  
    int *arr2 = new int[rightArrayLength];  

    int mainArrayIndex = s;
    for(int i=0; i<leftArrayLength; i++) {
        arr1[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    mainArrayIndex = mid + 1;
    for(int i=0; i<rightArrayLength; i++) {
        arr2[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    int i = 0;
    int j = 0;

    mainArrayIndex = s;
    while(i < leftArrayLength && j < rightArrayLength) {
        if(arr1[i] < arr2[j]) {
            arr[mainArrayIndex] = arr1[i];
            i++;
            mainArrayIndex++;
        }
        else {
            arr[mainArrayIndex] = arr2[j];
            j++;
            mainArrayIndex++;
        }
    }
    // copying
    while(i < leftArrayLength) {
        arr[mainArrayIndex] = arr1[i];
        i++;
        mainArrayIndex++;
    }
    while(j < rightArrayLength) {
        arr[mainArrayIndex] = arr2[i];
        j++;
        mainArrayIndex++;
    }
}

void mergeSort(int arr[], int s, int e) {
    // Base Case: We cannot divide the single element
    if(s >= e) return;
    // We will break the array in two halves
    int mid = (s+e)/2;
    // We will give the halves to recursion 
    // Left half will have end as the mid
    mergeSort(arr, s, mid);
    // Right half will have start as mid+1
    mergeSort(arr, mid+1, e);

    merge(arr, s, e, mid);
}

int main() {
    int arr[] = {7,2,4,3,1,5};
    int size = 6;
    int s = 0;
    int e = size-1;

    mergeSort(arr, s, e);

}