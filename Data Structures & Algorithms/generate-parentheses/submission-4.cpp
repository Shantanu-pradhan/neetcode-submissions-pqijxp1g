class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string s;
        generatep(n, s, res, 0, 0);
        return res;
    }
    void generatep(int n, string &s, vector<string>&res, int openN, int closeN){
        if(openN == n && openN == closeN){
            res.push_back(s);
            return;
        }
        if(openN < n){
            s+='(';
            generatep(n, s, res, openN+1, closeN);
            s.pop_back();
        }
        if(closeN < openN){
            s+=')';
            generatep(n, s, res, openN, closeN+1);
            s.pop_back();
        }
    }
};
