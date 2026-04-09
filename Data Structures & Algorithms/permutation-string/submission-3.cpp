class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>umap1;
        for(int i=0; i<s1.length(); i++){
            umap1[s1[i]]++;
        }
        int need = umap1.size();
        for(int i=0; i<s2.size(); i++){
            unordered_map<char, int>umap2;
            int want = 0;
            for(int j=i; j<s2.length(); j++){
                char c2 = s2[j];
                umap2[c2]++;
                if(umap1[c2] < umap2[c2]){
                    break;
                }
                if(umap1[c2] == umap2[c2]){
                    want++;
                }
                if(need == want){
                    return true;
                }
            }
        }
        return false;
    }
};
