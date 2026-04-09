class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        vector<pair<int, int>>vp;
        vector<int>res;
        for(auto n:nums){
            freq[n]++;
        }
        for(auto n:freq){
            vp.push_back({n.second, n.first});
        }
        sort(vp.begin(), vp.end());
        for(int i=vp.size()-1; i>=0; --i){
            if(res.size()==k){
                break;
            }
            res.push_back(vp[i].second);
        }
        return res;
    }
};
