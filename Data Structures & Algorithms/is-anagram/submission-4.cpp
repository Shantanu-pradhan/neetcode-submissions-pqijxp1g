class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        return (smap == tmap);
    }
};
