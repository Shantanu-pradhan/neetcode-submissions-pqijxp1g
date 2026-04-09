class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        sum_target(candidates, curr, target, 0, 0);
        return res;
    }
    void sum_target(vector<int>&arr, vector<int>&curr, int target, int sum, int indx)
    {
        if(sum == target)
        {
            res.push_back(curr);
            return;
        }
        if(indx >= arr.size() || sum > target)
        {
            return;
        }
        curr.push_back(arr[indx]);
        sum_target(arr, curr, target, sum+arr[indx], indx+1);
        curr.pop_back();
        int val = arr[indx];
        while(indx+1 < arr.size() && arr[indx] == arr[indx+1]){
            indx++;
        }
        sum_target(arr, curr, target, sum, indx+1);

    }
};
