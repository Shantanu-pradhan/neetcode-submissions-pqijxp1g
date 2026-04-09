class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>count;
        vector<pair<int, int>>pvector;
        for(auto num:nums){
            count[num]++;
        }
        for(auto it:count){
            pvector.push_back({it.second, it.first});
        }
        sort(pvector.rbegin(), pvector.rend());
        for(int i=0; i<k; i++){
            res.push_back(pvector[i].second);
        }
        return res;
    }
};
