class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        find_subset(nums, {}, 0);
        return res;
    }
    void find_subset(vector<int>&nums, vector<int>curr, int indx)
    {
        if(indx == nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[indx]);
        find_subset(nums, curr, indx+1);
        curr.pop_back();
        while(indx+1 < nums.size() && nums[indx+1] == nums[indx])
        {
            indx++;
        }
        find_subset(nums, curr, indx+1);
    }
};
