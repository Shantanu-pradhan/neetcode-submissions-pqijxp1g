class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>umap;
        int res = 0;
        int maxf = 0;
        int l = 0;
        for(int r=0; r<s.length(); r++){
            umap[s[r]]++;
            maxf = max(maxf, umap[s[r]]);
            while(r-l+1 - maxf > k){
                umap[s[l]]--;
                l++;
            }
            res = max(r-l+1,res);
        }
        return res;
        
    }
};
