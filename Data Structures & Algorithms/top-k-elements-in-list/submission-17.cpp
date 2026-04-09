class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>umap;
        vector<vector<int>>vct(nums.size()+1);
        vector<int>res;
        for(auto num: nums){
            umap[num]++;
        }
        for(auto pair: umap){
            vct[pair.second].push_back(pair.first);
        }
        for(int i = vct.size()-1; i>0; i--){
            for(auto val:vct[i]){
                        res.push_back(val);
                        if(res.size() == k){
                            return res;
                        }
            }
        }
        return res;

    }
};
