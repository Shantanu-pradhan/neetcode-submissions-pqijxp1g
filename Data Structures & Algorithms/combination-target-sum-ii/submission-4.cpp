class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>subset;
        sort(candidates.begin(), candidates.end());
        csum(candidates, 0, target, 0, subset, res);
        return res;
    }

    void csum(vector<int>&candidate, int i, int target, int total, vector<int>&subset, vector<vector<int>>&res){
        if(target == total){
            res.push_back(subset);
            return;
        }
        if(total > target || i >= candidate.size()){
            return;
        }

        subset.push_back(candidate[i]);
        csum(candidate, i+1, target, total+candidate[i], subset, res);
        subset.pop_back();
        while(i+1 < candidate.size() && candidate[i] == candidate[i+1]){
            i++;
        }
        csum(candidate, i+1, target, total, subset, res);
    }
};
