#include<iostream>
#include <limits.h>
using namespace std;

// PRINT ARRAY USING RECURSION
void printArray(int *arr, int size, int index) {
    if(index >= size) return;
    cout << arr[index] << " ";
    printArray(arr, size, index+1);
}

// PRINT REVERSED ARRAY USING RECURSION
void reversePrint(int *arr, int size) {
    if(size <= 0 ) return;
    cout << arr[size-1] << " ";
    reversePrint(arr, size - 1);
}

// SEARCH IN ARRAY USING RECURSION
bool search(int *arr, int index, int size, int element) {
    if(index >= size) return false;
    if(arr[index] == element) return true;
    search(arr, index+1, size, element);
}

// MIN ELEMENT IN ARRAY USING RECURSION
int minElement(int *arr, int index, int size) {
    if(index == size) return INT_MAX;
    int min = minElement(arr, index+1, size);
    if(arr[index] < min) {
        return arr[index];
    }
    return min;
}

int minElementUsingTailRecursion(int *arr, int index, int size, int min) {
    if(index == size) return min;
    if(arr[index] < min) {
        min = arr[index];
    }
    return minElementUsingTailRecursion(arr, index+1, size, min);
}

// MAX ELEMENT IN ARRAY USING RECURSION
int maxElement(int *arr,int index, int size) {
    if(index == size) return INT_MIN;
    int max = maxElement(arr, index+1, size);
    if(arr[index] > max) {
        return arr[index];
    }
    return max;
}

int main() {
    int arr[5] = {20, 10, 70, 40, 90};
    int size = 5;

    // printArray(arr, 5, 0);
    // cout << endl;
    // reversePrint(arr, 5);
    cout << endl;
    // cout << search(arr, 0, 5, 10);
    // cout << minElementUsingTailRecursion(arr, 0, 5, INT_MAX);
} 