class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>umap;
        int l=0, res=0;
        if(s.length() == 0){
            return 0;
        }
        for(int r=0; r<s.length(); r++){
            if(umap.find(s[r]) != umap.end()){
                l = max(l, umap[s[r]]+1);
            }
            umap[s[r]] = r;
            res = max(res, r-l+1);
        }
        return res;
    }
};
