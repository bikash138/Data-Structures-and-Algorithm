#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    vector<int> arr;

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    arr[5] = 60;

    int target = 400;
    // find returns a iterator which is a pointer to the element
    // SO we need to destructure it before printing it
    auto it = find(arr.begin(), arr.end(), target);
    cout << *it << endl;
    // If the element is not found then the iterator ends up pointing 
    // to one index after the the ending index of the vector 
    // THerefore printing *it will return 0 it element is not there
    
    return 0;
}