#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main () {
    vector<int> arr1(6);
    arr1[0] = 1;
    arr1[1] = 7;
    arr1[2] = 3;


    vector<int> arr2(6);
    arr2[0] = 3;
    arr2[1] = 4;
    arr2[2] = 5;


    int sum = inner_product(arr1.begin(), arr1.end(), arr2.begin(), 0);

    cout << "Sum: " << sum << "\n";

    
    return 0;
}