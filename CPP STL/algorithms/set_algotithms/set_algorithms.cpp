#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    vector<int> arr1(6);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;


    vector<int> arr2(6);
    arr2[0] = 3;
    arr2[1] = 4;
    arr2[2] = 5;

    vector<int> result; 

    // To find the union of the set
    set_union(arr1.begin(), arr2.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));

    // To find the intersection of the set
    set_intersection(arr1.begin(), arr2.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));

    // Difference betwen two vectors
    set_difference(arr1.begin(), arr2.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));

    // Remove the same numbers from bothe the vectors and keep the other
    set_symmetric_difference(arr1.begin(), arr2.end(), arr2.begin(), arr2.end(), inserter(result, result.begin()));
    
    for(int a: result) {
        cout << a << " ";
    }
    
    return 0;
}