class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>subset;
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        csum(candidates, target, 0, subset, res);
        return res;
    }
    void csum(vector<int>&candidates,
                        int target,
                        int i,
                        vector<int>&subset,
                        vector<vector<int>>&res)
    {
        if(target == 0){
            res.push_back(subset);
            return;
        }
        if(i >= candidates.size() || target < 0){
            return;
        }
        subset.push_back(candidates[i]);
        csum(candidates, target-candidates[i], i+1, subset, res);
        subset.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }
        csum(candidates, target, i+1, subset, res);
        return;
    }
};
