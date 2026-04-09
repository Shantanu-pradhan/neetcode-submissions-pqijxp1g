class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>umap;
        for(int i=0; i<numbers.size(); i++){
            if(umap.count(target-numbers[i])){
                return {umap[target-numbers[i]], i+1};
            }
            umap[numbers[i]] = i+1;
        }
        return {};
    }
};
