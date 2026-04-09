class Solution {
public:
    bool isAnagram(string s, string t) {
        //if the two strings are anagram of each other
        int slen = s.length();
        int tlen = t.length();
        if(slen != tlen){
            return false;
        }
        int arr_char[26] = {0};
        for(int i=0; i<slen; i++){
            arr_char[s[i] - 'a']++;
            arr_char[t[i] - 'a']--;
        }
        /*for(int i=0; i<tlen; i++){
            arr_char[t[i] - 'a']--;
        }*/
        for(int i=0; i<26; i++){
            if(arr_char[i] != 0){
                return false;
            }
        }
        return true;
    }
};
