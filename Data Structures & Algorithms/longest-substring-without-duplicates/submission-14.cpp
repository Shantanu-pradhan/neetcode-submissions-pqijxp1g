class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max_len = 0;
        vector<int>maping(128,-1);
        for(int right = 0; right < s.length(); right++){
            if(maping[s[right]] != -1){
                left = max(left, maping[s[right]]+1);
            }
            maping[s[right]] = right;
            max_len = max(max_len, right-left+1);
        }
        return max_len;
    }
};
