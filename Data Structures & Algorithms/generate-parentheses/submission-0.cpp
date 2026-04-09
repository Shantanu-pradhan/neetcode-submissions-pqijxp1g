class Solution {
public:
    void back_track(int oN, int cN, int N, vector<string>&res, string stack){
        if(oN==cN && (oN == N)){
            res.push_back(stack);
            return;
        }
        if(oN < N){
            stack+='(';
            back_track(oN+1,cN,N,res,stack);
            stack.pop_back();
        }
        if(cN<oN){
            stack.push_back(')');
            back_track(oN,cN+1,N,res,stack);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string stack;
        int oN=0, cN=0;
        back_track(oN,cN,n,res,stack);
        return res;
    }
};
