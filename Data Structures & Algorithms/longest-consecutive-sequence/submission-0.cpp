class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int res=0;
        for(auto n:nums){
            if(uset.find(n-1)== uset.end()){
                int length=1;
                while(uset.find(n+length) != uset.end()){
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;

    }
};
