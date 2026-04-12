class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<bool>check(nums.size(), false);
        vector<int>perm;
        find_perm(nums, perm, check, res);
        return res;
    }
    void find_perm(vector<int>&nums, vector<int>&perm, vector<bool>&check, vector<vector<int>>&res)
    {
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(check[i] || (i>0 && nums[i] == nums[i-1] && !check[i-1])){
                continue;
            }
            check[i] = true;
            perm.push_back(nums[i]);
            find_perm(nums, perm, check, res);
            check[i] = false;
            perm.pop_back();
        }
        return;
    }
};