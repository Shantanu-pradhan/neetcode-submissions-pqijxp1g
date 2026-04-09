class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>sarr;
        int start=0, end=0, res=0;
        int slen=s.length();
        for(end=0; end<slen; end++){
            while(sarr.find(s[end]) != sarr.end()) {
                sarr.erase(s[start]);
                start++;
            }
            res=max(res, end-start+1);
            sarr.insert(s[end]);
        }
        return res;
    }
};
