class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        find_comb(nums, res, 0);
        return res;
    }
    void find_comb(vector<int>&nums, vector<vector<int>>&res, int index)
    {
        if(index >= nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            find_comb(nums, res, index+1);
            swap(nums[i], nums[index]);
        }
    }
};
