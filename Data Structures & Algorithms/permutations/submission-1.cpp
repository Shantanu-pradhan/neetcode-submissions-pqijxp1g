class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> permute(vector<int>& nums) {
        find_comb(nums, 0);
        return res; 
    }
    void find_comb(vector<int>nums, int indx)
    {
        if(indx == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=indx; i<nums.size(); i++)
        {
            swap(nums[i], nums[indx]);
            find_comb(nums, indx+1);
            swap(nums[i], nums[indx]);
        }
    }
};
