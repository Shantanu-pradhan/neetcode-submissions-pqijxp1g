class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //store the last element of each vector to separate vector with the index asthe row
        vector<int>lelement;
        int m = matrix.size();
        if(m == 0){
            return false;
        }
        int n = matrix[0].size();
        if(n == 0){
            return false;
        }
        for(int i=0; i<matrix.size(); i++){
            lelement.push_back(matrix[i][n-1]);
        }

        //Perform binary search
        int l = 0;
        int r = m-1;
        int mid = 0;
        while(l <= r){
            mid = l+(r-l)/2;
            if(target == lelement[mid]){
                l = mid;
                break;
            }
            else if(target > lelement[mid]){
                l = mid+1;
            }else {
                r = mid-1;
            }
        }

        //Find the specific index
        int row = l;
        if(row >= m || row < 0){
            return false;
        }
        if(target < matrix[row][0]){
            return false;
        }
        //Perform binary search in that row to find the target
        l = 0;
        r = n-1;
        while(l <= r){
            mid = l+(r-l)/2;
            if (target == matrix[row][mid]){
                return true;
            }
             else if(target < matrix[row][mid]){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if(matrix[row][mid] == target){
            return true;
        }
        
        return false;
        
    }
};
