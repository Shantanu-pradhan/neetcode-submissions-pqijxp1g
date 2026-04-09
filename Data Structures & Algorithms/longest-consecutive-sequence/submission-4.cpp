class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int count = 0;
        int max_seq = 0;
        for(int num:nums){
            if(uset.find(num-1) == uset.end()){
                while(uset.find(num++) != uset.end()){
                    count++;
                }
                max_seq = max(count, max_seq);
                count = 0;
            }
        }
        return max_seq;
    }
};
