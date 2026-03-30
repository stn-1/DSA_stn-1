
#include<iostream>
#include<vector>
using namespace std;
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int top = 0, bottom = m - 1;
    while (top <= bottom) {
        int mid = (top + bottom) / 2;
        if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid2 = (left + right) / 2;
                if (matrix[mid][mid2] == target) return true;
                else if (matrix[mid][mid2] < target) left = mid2 + 1;
                else right = mid2 - 1;
            }
            return false;
        } else if (target < matrix[mid][0]) {
            bottom = mid - 1;
        } else {
            top = mid + 1;
        }
    }
    return false;
}
int main(){
    
    return 0;
}