class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        back_track(nums, curr, 0, target);
        return res;
    }
    void back_track(vector<int>&arr, vector<int>&curr, int i, int target)
    {
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target <=0 || i >= arr.size()){
            return;
        }
        curr.push_back(arr[i]);
        back_track(arr, curr, i, target-arr[i]);
        curr.pop_back();
        back_track(arr, curr, i+1, target);
    }
};
