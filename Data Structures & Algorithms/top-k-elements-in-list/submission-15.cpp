class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        vector<vector<int>>list(nums.size()+1);
        unordered_map<int, int>umap;
        for(int num:nums){
            umap[num]++;
        }
        for(auto pair:umap){
            list[pair.second].push_back(pair.first);
        }
        for(int i=list.size()-1; i>0; i--){
            for(int num:list[i]){
                res.push_back(num);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return {};
    }
};
