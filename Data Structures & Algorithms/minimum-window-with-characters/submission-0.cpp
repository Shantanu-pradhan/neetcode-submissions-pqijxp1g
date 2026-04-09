class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int >mcnt, mwnd;
        int ssize = s.length();
        int tsize = t.length();
        int have =0; 
        int need=tsize;
        int res = INT_MAX;
        int start = 0;
        pair <int, int>resl={-1,-1};
        for(int e=0 ;e<tsize; e++){
            mcnt[t[e]]++;
        }
        for(int end=0; end<ssize;end++){
            mwnd[s[end]]++;
            if(mcnt.count(s[end]) && (mcnt[s[end]] >= mwnd[s[end]])){
                have++;
            }
            while(have == need){
                if(res > end-start+1){
                    res = end-start+1;
                    resl = {start, end};
                }
                mwnd[s[start]]--;
                if(mcnt.count(s[start]) && (mcnt[s[start]] > mwnd[s[start]])){
                    have--;
                }
                start++;
            }
        }
        return res == INT_MAX ? "":s.substr(resl.first, res);
    }
};