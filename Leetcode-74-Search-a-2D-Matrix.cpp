/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/search-a-2d-matrix/description/
 * runtime: 0ms
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(target == matrix[mid][0]) {
                return true;
            } else if(target > matrix[mid][0]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        if(r < 0) return false; // target is smaller than the smallest value in the matrix 
        int row = r; // r will be the row we need to search
        l = 0; r = matrix[row].size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(target == matrix[row][mid]) {
                return true;
            } else if(target > matrix[row][mid]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return false;
    }
};