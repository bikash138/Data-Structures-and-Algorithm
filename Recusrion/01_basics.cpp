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

// FIND ODD ELEMENTS IN AN ARRAY
void oddElement(int *arr, int index, int size) {
    if(index >= size) return;
    if(arr[index] & 1) {
        cout << arr[index] << " ";
    }
    oddElement(arr, index+1, size);
}

// IMPLEMENT BINARY SEARCH USING RECURSION
int recursiveBinarySearch(int *arr, int s, int e, int target) {
    // If end crossed start means the target is not present
    if(s > e) {
        return -1;
    }
    // Get the initial mid element
    int mid = (s+e)/2;
    // If target found then simply return it
    if(arr[mid] == target) {
        return mid;
    }
    /*
    If target is smaller than mid term then 
    call the recursive function for the left half
    after shifting the end pointer
    */
    if(target < arr[mid]) {
        int recAns = recursiveBinarySearch(arr, s, mid-1, target);
        return recAns;
    } 
    // Else right shift of the start pointer
    else {
        int recAns = recursiveBinarySearch(arr, mid+1, e, target);
        return recAns;
    }
}

void printDigitsUsingRecursion(int num) {
    if(num == 0) return;
    int digit = num % 10;
    num = num / 10;
    printDigitsUsingRecursion(num);
    cout << digit << ' ';
}

bool isSortedArray(int *arr, int index, int size) {
    if(index == size-1) return true;
    if(arr[index] > arr[index+1]) {
        return false;
    }
    return isSortedArray(arr, index+1, size);
}

int main() {
    int arr[5] = {20,310, 700, 4000, 9000};
    int size = 5;

    // printArray(arr, 5, 0);
    // cout << endl;
    // reversePrint(arr, 5);
    cout << endl;
    // cout << search(arr, 0, 5, 10);
    // cout << minElementUsingTailRecursion(arr, 0, 5, INT_MAX);
    // oddElement(arr, 0, 5);
    // printDigitsUsingRecursion(3214);
    cout << isSortedArray(arr, 0, size);
}