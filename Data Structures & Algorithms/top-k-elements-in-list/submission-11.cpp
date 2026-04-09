class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>umap;
        for(int num:nums){
            umap[num]++;
        }
        vector<pair<int, int>>vpair;
        for(auto &p:umap){
            vpair.push_back({p.second, p.first});
        }
        sort(vpair.rbegin(), vpair.rend());
        vector<int>res;
        for(int i=0; i<k; i++){
            res.push_back(vpair[i].second);
        }
        return res;
    }
};
