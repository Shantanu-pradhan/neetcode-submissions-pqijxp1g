class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for(int i=0; i<s.length(); i++){
            unordered_map<char, int>umap;//vector is good
            int mfreq = 0;
            for(int j=i; j<s.length(); j++){
                umap[s[j]]++;
                mfreq = max(mfreq, umap[s[j]]);
                if((j-i+1 - mfreq) <= k){
                    res = max(res, j-i+1);
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
