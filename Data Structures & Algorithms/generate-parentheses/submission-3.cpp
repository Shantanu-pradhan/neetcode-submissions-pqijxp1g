class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr;
        generate_all(res, n, 0, 0, curr);
        return res;
    }
    void generate_all(vector<string>&res, int n, int l, int r, string &curr)
    {
        if(l == r && l == n){
            res.push_back(curr);
            return;
        }
        if(l < n){
            //curr +='(';
            curr.push_back('(');
            generate_all(res, n, l+1, r, curr);
            curr.pop_back();
        }
        if(r < l){
            curr.push_back(')');
            generate_all(res, n, l, r+1, curr);
            curr.pop_back();
        }
    }
};
