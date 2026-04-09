class Solution {
public:
        vector<vector<int>>res;
        vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        find_subset(nums, 0, subset);
        return res;
    }
    void find_subset(vector<int>&nums, int indx, vector<int>&subset)
    {
        if(indx >= nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[indx]);
        find_subset(nums, indx+1, subset);
        subset.pop_back();
        find_subset(nums, indx+1, subset);
    }
};
