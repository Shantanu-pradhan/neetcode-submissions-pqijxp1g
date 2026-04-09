class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>umap1;
        for(int i=0; i<s1.size(); i++){
            umap1[s1[i]]++;
        }
        int need = umap1.size();
        for(int i=0; i<s2.size(); i++){
            unordered_map<char, int>umap2;
            int want = 0;
            for(int j=i; j<s2.size(); j++){
                char ch = s2[j];
                umap2[ch]++;
                if(umap1[ch] < umap2[ch]){
                    break;
                }
                if(umap1[ch] == umap2[ch]){
                    want++;
                }
                if(want == need){
                    return true;
                }
            }
        }
        return false;
    }
};
