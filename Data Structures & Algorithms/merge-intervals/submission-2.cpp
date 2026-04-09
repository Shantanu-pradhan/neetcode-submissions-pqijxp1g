class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        int first = 0;
        int second = 0;
        for(auto &interval:intervals){
            first = interval[0];
            second = interval[1];
            if(first <= res.back()[1]){
                res.back()[1] = max(second, res.back()[1]);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};
