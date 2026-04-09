class Solution {
public:
    bool isAnagram(string s, string t) {
        string s2 = s;
        string t2 = t;
        sort(s2.begin(), s2.end());
        sort(t2.begin(), t2.end());
        if(s2 == t2){
            return true;
        }
        return false;
    }
};
