class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>umap;
        int res = 0;
        int l=0;
        for(int r=0; r<s.length(); r++){
            if(umap.find(s[r]) == umap.end()){
                umap[s[r]] = r;
                res = max(res, r-l+1);
            } else{
                if(umap[s[r]] < l){
                    res = max(res, r-l+1);
                }
                l = max(l, umap[s[r]]+1);
                umap[s[r]] = r;
            }
        }
        return res;
        
    }
};
