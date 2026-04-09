class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s2len=s2.length();
        int s1len=s1.length();
        int start=0;
        if(s1len > s2len){
            return false;
        }
        unordered_map<char, int>umap1;
        unordered_map<char, int>umap2;
        for(int end=0; end < s1len; end++){
            umap1[s1[end]]++;
            umap2[s2[end]]++;
        }
        if(s1len == s2len){
            if(umap1 == umap2){
                return true;
            } else {
                return false;
            }
        } else if(umap1 == umap2){
            return true;
        }
        for(int end = s1len; end < s2len; end++){
            umap2[s2[start]]--;
            if(umap2[s2[start]] <= 0){
                umap2.erase(s2[start]);
            }
            start++;
            umap2[s2[end]]++;
            if(umap1 == umap2){
                return true;
            }
        }
        return false;
    }
};