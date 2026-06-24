#include <iostream>
#include <vector>
using namespace std;

void print2dArray(vector<vector<int>> matrix) {
  for(int i=0; i<matrix.size(); i++) {
    for(int j=0; j<matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    };
    cout << endl;
  }
}

int main() {
  vector<vector<int>> matrix = {
    {10, 20, 30},
    {40, 50, 60},
    {70, 80, 90}
  };
  // print2dArray(matrix);
  //Deltion
  matrix[1].erase(matrix[1].begin() + 1);
  print2dArray(matrix);
  matrix[1].insert(matrix[1].begin() + 1, 88);
  print2dArray(matrix);

}