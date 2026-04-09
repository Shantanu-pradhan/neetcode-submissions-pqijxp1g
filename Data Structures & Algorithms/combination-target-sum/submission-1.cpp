class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        back_track(nums, curr, 0, target);
        return res;
    }
    void back_track(vector<int>&arr, vector<int>&curr, int indx, int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target <= 0 || indx >= arr.size()){
            return;
        }
        curr.push_back(arr[indx]);
        back_track(arr, curr, indx, target-arr[indx]);
        curr.pop_back();
        back_track(arr, curr, indx+1, target);
    }
};
