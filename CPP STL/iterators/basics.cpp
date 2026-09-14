#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
    vector<string> languages = {"Python", "C++", "Java"};

    // we are creating a iterator to a string
    vector<string>::iterator itr;
    

    vector<int> result; 

    // iteratre over all the elements
    for(itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << endl;
    }
    
    for(int a: result) {
        cout << a << " ";
    }
    
    return 0;
}