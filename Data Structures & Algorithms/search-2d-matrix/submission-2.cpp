class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target){
                int l=0;
                int r=matrix[i].size()-1;
                int m=0;
                while(l<=r){
                    m = l+(r-l)/2;
                    if(matrix[i][m] > target){
                        r = m-1;
                    } else if(matrix[i][m] < target){
                        l = l+1;
                    } else{
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
