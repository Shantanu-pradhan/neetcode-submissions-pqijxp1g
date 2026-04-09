class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int, int>umap;
        for(int i=0; i<nums.size(); i++){
            int tmp = target - nums[i];
            if(umap.find(tmp) != umap.end()){
                return {umap[tmp], i};
            } else {
                umap[nums[i]] = i;
            }
        }
        return {0, 0};
    }
};
