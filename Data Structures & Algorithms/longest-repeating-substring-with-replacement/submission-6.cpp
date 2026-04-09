class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>ucount;
        int l = 0;
        int maxf = 0;
        int res = 0;
        for(int r=0; r<s.length(); r++){
            ucount[s[r]]++;
            maxf = max(maxf, ucount[s[r]]);
            if(r-l+1 - maxf > k){
                ucount[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
