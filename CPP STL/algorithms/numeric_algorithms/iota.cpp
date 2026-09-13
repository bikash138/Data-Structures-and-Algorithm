#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main () {
    vector<int> arr(6);

    // Used to fill the container with a continuous count
    iota(arr.begin(), arr.end(), 250);


    for(int a: arr) {
        cout << a << " ";
    }
    
    return 0;
}