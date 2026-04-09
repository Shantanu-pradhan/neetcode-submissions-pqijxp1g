class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int res = 0;
        int length = 0;
        for(int num:nums){
            if(uset.find(num-1) == uset.end()){
                length = 1;
                while(uset.find(num+length) != uset.end()){
                    length=length+1;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};
