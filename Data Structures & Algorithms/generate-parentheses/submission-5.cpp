class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string substr;
        find_allstring(n, res, 0, 0, substr);
        return res;
    }
    void find_allstring(int n, vector<string>&res, int openN, int closeN, string &substr){
        if(openN == closeN && openN == n){
            res.push_back(substr);
            return;
        }
        if(openN < n){
            substr.push_back('(');
            find_allstring(n, res, openN+1, closeN, substr);
            substr.pop_back();
        }
        if(closeN < openN){
            substr.push_back(')');
            find_allstring(n, res, openN, closeN+1, substr);
            substr.pop_back();
        }
        return;
    }
};
