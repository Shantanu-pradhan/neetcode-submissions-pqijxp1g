class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int>umaps;
        unordered_map<char, int>umapt;
        for(int i=0 ; i<s.length(); i++){
            umaps[s[i]]++;
            umapt[t[i]]++;
        }
        return (umaps == umapt) ? true : false;

    }
};
