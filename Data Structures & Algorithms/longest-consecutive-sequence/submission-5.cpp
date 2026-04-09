class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int mx = 0;
        if(nums.size() == 0){
            return 0;
        }
        for(int i=0; i<nums.size(); i++){
            if(uset.find(nums[i]-1) == uset.end()){
                int length = 1;
                while(uset.find(nums[i]+length) != uset.end()){
                    length++;
                }
                mx = max(mx, length);
            }
        }
        return mx;
    }
};
