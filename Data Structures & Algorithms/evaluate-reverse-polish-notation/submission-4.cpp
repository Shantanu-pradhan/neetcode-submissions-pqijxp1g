class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>sstack;
        int a = 0;
        int b = 0;
        for(string s:tokens){
            if(s == "+"){
                a = sstack.top();
                sstack.pop();
                b = sstack.top();
                sstack.pop();
                sstack.push(a+b);
            }else if(s == "-"){
                a = sstack.top();
                sstack.pop();
                b = sstack.top();
                sstack.pop();
                sstack.push(b-a);
            }else if(s == "*"){
                a = sstack.top();
                sstack.pop();
                b = sstack.top();
                sstack.pop();
                sstack.push(b*a);
            }else if(s == "/"){
                a = sstack.top();
                sstack.pop();
                b = sstack.top();
                sstack.pop();
                sstack.push(b/a);
            }else{
                sstack.push(stoi(s));
            }
        }
        return sstack.top();
    }
};
