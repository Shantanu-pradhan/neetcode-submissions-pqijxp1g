class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(auto const &interval:intervals){
            int last_ele = res.back()[1];
            if(last_ele >= interval[0]){
                res.back()[1] = max(last_ele, interval[1]);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};
