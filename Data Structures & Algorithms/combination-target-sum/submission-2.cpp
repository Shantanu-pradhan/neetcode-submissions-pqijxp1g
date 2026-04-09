class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>sset;
        find_csum(nums, 0, res, sset, target);
        return res;
    }
    void find_csum(vector<int>&num, int indx, vector<vector<int>>&res, vector<int>sset, int target)
    {
        if(target == 0){
            res.push_back(sset);
            return;
        }
        if(target < 0 || indx >= num.size()){
            return;
        }
        sset.push_back(num[indx]);
        find_csum(num, indx, res, sset, target-num[indx]);
        sset.pop_back();
        find_csum(num, indx+1, res, sset, target);
    }
};
