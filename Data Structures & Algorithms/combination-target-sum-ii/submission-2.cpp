class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>sset;
        sort(candidates.begin(), candidates.end());
        find_comsum2(candidates, res, sset, 0, target);
        return res;
    }
    void find_comsum2(vector<int>&candidates, vector<vector<int>>&res,
                        vector<int>&sset, int indx, int target)
    {
        if(target == 0){
            res.push_back(sset);
            return;
        }
        if((indx > candidates.size()-1) || target < 0){
            return;
        }
        sset.push_back(candidates[indx]);
        find_comsum2(candidates, res, sset, indx+1, target-candidates[indx]);
        sset.pop_back();
        while(indx+1 <= candidates.size()-1 && candidates[indx] == candidates[indx+1]){
            indx++;
        }
        find_comsum2(candidates, res, sset, indx+1, target);
    }
};
