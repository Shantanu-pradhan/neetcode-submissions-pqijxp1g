class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>tstack;
        int a=0;
        int b=0;
        for(const string &c:tokens){
            if(c == "+"){
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(b+a);
            }else if(c == "-"){
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(b-a);

            }else if(c == "*"){
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(b*a);

            }else if(c == "/"){
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(b/a);

            }else{
                tstack.push(stoi(c));
            }
        }
        return tstack.top();
    }
};
