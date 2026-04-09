class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a=0;
        int b=0;
        stack<int>tstack;
       for(const string &c:tokens){
            if (c == "+") {
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(a+b);
            } else if(c == "-") {
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(b-a);
            } else if(c == "*") {
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(a*b);

            } else if(c == "/") {
                a = tstack.top();
                tstack.pop();
                b = tstack.top();
                tstack.pop();
                tstack.push(b/a);
            } else {
                tstack.push(stoi(c));
            }
       }
       return tstack.top();
    }
};
