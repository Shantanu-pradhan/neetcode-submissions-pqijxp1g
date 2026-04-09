class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()){
            return false;
        }
        vector<int>s1count(128, 0);
        vector<int>s2count(128, 0);
        for(int i=0; i<s1.length(); i++){
            s1count[s1[i]]++;
            s2count[s2[i]]++;
        }
        int match = 0;
        for(int i=0; i<128; i++){
            if(s1count[i] == s2count[i]){
                match++;
            }
        }
        int l=0;
        int index =0;
        for(int r=s1.length(); r<s2.length(); r++){
            if(match == 128){
                return true;
            }
            index = s2[r];
            s2count[index]++;
            if(s1count[index] == s2count[index]){
                match++;
            } else if(s1count[index]+1 == s2count[index]){
                match--;
            }
            index = s2[l];
            s2count[index]--;
            if(s1count[index] == s2count[index]){
                match++;
            } else if(s1count[index]-1 == s2count[index]){
                match--;
            }
            l++;
        }
        return (match == 128);
    }
};
