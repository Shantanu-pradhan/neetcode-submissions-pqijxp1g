class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>umap1;
        for(int i=0; i<s1.length(); i++){
            umap1[s1[i]]++;
        }
        int need = umap1.size();
        for(int i=0; i<s2.length(); i++){
            unordered_map<char, int>umap2;
            int cnt = 0;
            for(int j = i; j<s2.length(); j++){
                char c = s2[j];
                umap2[c]++;
                if(umap1[c] < umap2[c]){
                    break;
                }
                if(umap1[c] == umap2[c]){
                    cnt++;
                }
                if(cnt == need){
                    return true;
                }
            }

        }
        return false;
    }
};
