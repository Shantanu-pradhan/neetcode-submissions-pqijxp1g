class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() == 0){
            return "";
        }
        int resLen = INT_MAX;

        unordered_map<char, int>tcount, window;
        for(char ch:t){
            tcount[ch]++;
        }
        int need = 0;
        int have = 0;
        need = tcount.size();
        int l=0;
        pair<int,int>res = {-1,-1};
        for(int r = 0; r<s.length(); r++){
            char ch = s[r];
            window[ch]++;
            if(tcount.count(ch) && (tcount[ch] == window[ch])){
                have++;
            }
            while(have == need){
                //update the res and the index
                if(r-l+1 < resLen){
                    resLen = r-l+1;
                    res = {l,r};
                }
                char ch = s[l];
                window[ch]--;
                if(tcount.count(ch) && window[ch] < tcount[ch]){
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "":s.substr(res.first, resLen);
    }
};
