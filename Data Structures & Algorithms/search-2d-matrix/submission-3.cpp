class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int top = 0;
        int bot = row;
        int middle = 0;
        while(top <= bot){
            middle = (top+bot)/2;
            if(target > matrix[middle][col]){
                top = middle+1;
            } else if(target < matrix[middle][0]){
                bot = middle-1;
            } else {
                break;
            }
        }
        if(top > bot){
            return false;
        }
        int l = 0;
        int r = col;
        int m = 0;
        while(l <= r){
            m = (l+r)/2;
            if(target > matrix[middle][m]){
                l = m+1;
            } else if(target < matrix[middle][m]){
                r = m-1;
            } else {
                return true; 
            }
        }
        return false;
    }
};
