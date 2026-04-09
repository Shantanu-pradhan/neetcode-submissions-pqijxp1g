class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>subset;
        vector<vector<int>>res;
        find_subset(nums, 0, subset, res);
        return res;
    }

    void find_subset(vector<int>&nums, int i, vector<int>&subset, vector<vector<int>>&res){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        find_subset(nums, i+1, subset, res);
        subset.pop_back();
        while(i < nums.size()-1 && nums[i] == nums[i+1]){
            i++;
        }
        find_subset(nums, i+1, subset, res);
        return;
    }

};
