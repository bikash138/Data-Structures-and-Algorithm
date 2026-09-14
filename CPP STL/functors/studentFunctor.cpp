#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student {
    public: 
        int marks;
        string name;
        Student() {

        }
        Student (int m, string n) {
            this->marks = m;
            this->name = n;
        }
};

class StudentComparator {
    public:
        bool operator()(Student a, Student b) {
            // This keeps the student with less marks first
            return a.marks < b.marks;
        }
};

int main() {

    vector<Student> arr;

    arr.push_back(Student(90, "Bikash"));
    arr.push_back(Student(89, "Ram"));
    arr.push_back(Student(95, "Shyam"));

    sort(arr.begin(), arr.end(), StudentComparator());

    for(Student s : arr) {
        cout << s.marks << " " << s.name << endl;
    }

    return 0;

}