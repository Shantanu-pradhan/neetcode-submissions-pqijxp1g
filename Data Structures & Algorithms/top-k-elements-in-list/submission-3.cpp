class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        vector<pair<int, int>>freq(nums.size()+1);
        vector<int>res;
        for(auto n:nums){
            count[n]++;
        }
        for(auto n:count){
            freq.push_back({n.second, n.first});
        }
        sort(freq.begin(), freq.end());
        for(int i=freq.size()-1; i>=0; --i){
            if(res.size() == k){
                break;
            }
            res.push_back(freq[i].second);
        }
        return res;
    }
};
