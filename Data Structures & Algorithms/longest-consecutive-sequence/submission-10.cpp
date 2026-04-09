class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset(nums.begin(), nums.end());
        int max_seq = 0;
        if(!uset.empty()){
            max_seq = 1;
        }
        for(auto i:uset){
            if(uset.find(i-1) == uset.end()){
                int j=1;
                while(uset.find(i+j) != uset.end()){
                    j++;
                }
                max_seq = max(max_seq, j);
            }
        }
        return max_seq;
    }
};
