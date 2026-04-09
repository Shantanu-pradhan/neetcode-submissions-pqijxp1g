class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        sort(nums.begin(), nums.end());
        find_allsubs(nums, res, curr, 0);
        return res;
    }
    void find_allsubs(vector<int>&nums, vector<vector<int>>&res, vector<int>&curr, int indx)
    {
        if(indx == nums.size())
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[indx]);
        find_allsubs(nums, res, curr, indx+1);
        curr.pop_back();
        while(indx+1 < nums.size() && nums[indx] == nums[indx+1])
        {
            indx++;
        }
        find_allsubs(nums, res, curr, indx+1);
    }
};
