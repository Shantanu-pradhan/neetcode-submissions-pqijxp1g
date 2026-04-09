class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        all_comb(nums, curr, 0);
        return res;
    }
    void all_comb(vector<int>&arr, vector<int>&curr, int indx)
    {
        if(indx >= arr.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(arr[indx]);
        all_comb(arr, curr, indx+1);
        curr.pop_back();
        all_comb(arr, curr, indx+1);
    }
};
