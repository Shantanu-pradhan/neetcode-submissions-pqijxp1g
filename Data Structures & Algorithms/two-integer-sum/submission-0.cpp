class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> umap;
        vector<int>res;
        int n = nums.size();
        int val = 0;
        for(int i=0; i<n; i++){
            val = target - nums[i];
            if(umap.find(val)!=umap.end()){
                return {umap[val], i};
            } else {
                umap[nums[i]] = i;
            }
        }
        return {};
    }
};
