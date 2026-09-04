#include<iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int solution(vector<int> &arr) {
    // Sort the Array so that all the repeating elements comes together
    sort(arr.begin(), arr.end());

    // We have initialised the variables with the data of first element
    int maxFreq = 1;
    int mode = arr[0];
    int cf = 1; // <--Current frequency

    // We will start checking from the second cell
    for(int i=1; i<arr.size(); i++) {
        // We will increase the freq whenever we get same element
        if(arr[i] == arr[i-1]){
            cf++;
        }
        // Other wise the current frequency will be 1
        else {
            cf = 1;
        }
        // Doing this if cf changes we need to update the maxFreq and the mode with the element
        // For two numbers having same freq we will consider the smaller number
        // Hence we are using > sign and not >= therefore the smaller number's index remains entact
        if(cf > maxFreq) {
            // New max freq 
            maxFreq = cf;
            mode = arr[i];
        }
    }
    return mode;

}

int main () {
    vector<int> arr{3,3,2,1,5,1};

    int ans = solution(arr);

    cout << ans;
}