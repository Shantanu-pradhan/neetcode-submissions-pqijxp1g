class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        vector<vector<int>>freq(nums.size()+1);
        vector<int>res;
        for(auto n:nums){
            count[n]++;
        }
        for(auto n:count){
            freq[n.second].push_back(n.first);
        }
        for(int i=freq.size()-1; i>=0; --i){
            if(res.size() == k){
                break;
            }
            for(auto n:freq[i]){
                res.push_back(n);
            }
        }
        return res;
    }
};
