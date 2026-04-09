class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            //for(int j=0; i<matrix[i].size(); j++){
                if(matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target){
                    if(find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end()){
                        return true;
                    }
                }
            //}
        }
        return false;
    }
};
