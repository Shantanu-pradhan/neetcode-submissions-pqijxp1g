class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
     vector<vector<int>>res;
     vector<int>subset;
     find_comb(nums, 0, target, subset, res);
     return res;   
    }
    void find_comb(vector<int>&nums, int i, int target, vector<int>&subset, vector<vector<int>>&res){
        if(target == 0){
            res.push_back(subset);
            return;
        }
        if(target < 0 || i >= nums.size()){
            return;
        }
        subset.push_back(nums[i]);
        find_comb(nums, i, target-nums[i], subset, res);
        subset.pop_back();
        find_comb(nums, i+1, target, subset, res);
        return;
    }
};
