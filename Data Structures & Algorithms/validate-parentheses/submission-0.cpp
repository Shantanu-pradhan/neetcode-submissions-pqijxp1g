class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char>bmap = {
            {'}','{'},
            {']','['},
            {')','('}
        };
        stack<char>bstack;
        if(s.length() == 0){
            return false;
        }
        for(char c:s){
            if(bmap.count(c)){
                if(!bstack.empty() && (bstack.top() == bmap[c])){
                    bstack.pop();
                } else {
                    return false;
                }
            } else {
                bstack.push(c);
            }
        }
        return bstack.empty();
    }
};
