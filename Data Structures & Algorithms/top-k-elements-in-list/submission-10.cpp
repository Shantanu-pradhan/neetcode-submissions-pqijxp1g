class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>numap;
        for(int n:nums){
            numap[n]++;
        }
        vector<pair<int,int>>nuvector;
        for(auto pair:numap){
            nuvector.push_back({pair.second, pair.first});
        }
        //nuvector.sort(rbegin(), rend());
        sort(nuvector.rbegin(), nuvector.rend());
        vector<int>res;
        for(int i=0; i<k; i++){
            res.push_back(nuvector[i].second);
        }
        return res;
    }
};
