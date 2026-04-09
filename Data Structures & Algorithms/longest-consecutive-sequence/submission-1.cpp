class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int res = 0;
        int curr_res = 0;
        for(int num: nums){
            int next = num+1;
            curr_res = 1;
            while(uset.find(next) != uset.end()){
                next = next+1;
                curr_res = curr_res+1;
            }
            res = max(res, curr_res);
        }
        return res;
    }
};
