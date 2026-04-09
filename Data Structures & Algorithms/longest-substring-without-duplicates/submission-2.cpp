class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>uset;
        if(s.length() == 0){
            return 0;
        }
        int l=0, res=0;
        for(int r=0; r<s.length(); r++){
            while(uset.find(s[r]) != uset.end()){
                uset.erase(s[l]);
                l++;
            }
            uset.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
