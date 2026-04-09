class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>umap;
        int res = 0;
        int l = 0;
        int r = 0;
        for(r=0; r<s.size(); r++){
            if(umap.find(s[r]) != umap.end()){
                l = max(l, umap[s[r]]+1);
            }
            res = max(res, r-l+1);
            umap[s[r]] = r;
        }
        return res;
    }
};
