class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        find_allcomb(res, nums, 0);
        return res;
    }
    void find_allcomb(vector<vector<int>>&res, vector<int>&nums, int indx)
    {
        //base case
        if(indx >= nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=indx; i<nums.size(); i++){
            swap(nums[i], nums[indx]);
            find_allcomb(res, nums, indx+1);
            swap(nums[i], nums[indx]);
        }
    }

};
