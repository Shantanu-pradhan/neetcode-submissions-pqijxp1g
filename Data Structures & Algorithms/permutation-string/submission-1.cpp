class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>umap1;
        for(int i=0; i<s1.length(); i++){
            umap1[s1[i]-'a']++;
        }
        int need = umap1.size();
        for(int i=0; i<s2.length(); i++){
            unordered_map<char, int>umap2;
            int curr = 0;
            for(int j=i; j<s2.length(); j++){
                char c = s2[j];
                umap2[c-'a']++;
                if(umap1[c-'a'] < umap2[c-'a']){
                    break;
                }
                if(umap1[c-'a'] == umap2[c-'a']){
                    curr++;
                }
                if(curr == need){
                    return true;
                }
            }

        }
        return false;
    }
};
