class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> sarr;
        int slen=s.length();
        int start =0, end=0;
        int res=0;
        for(end=0; end<slen; end++){
            while(sarr.find(s[end]) != sarr.end()){
                sarr.erase(s[start]);
                start++;
            }
            res=max(res, end-start+1);
            sarr.insert(s[end]);
        }
        return res;
    }
};
