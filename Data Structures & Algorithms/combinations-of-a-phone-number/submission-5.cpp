class Solution {
public:
    vector<string>key = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string substr;
        if(digits.length() == 0){
            return res;
        }
        find_letter(digits, res, substr, 0);
        return res;
    }
    void find_letter(string &digits, vector<string>&res, string &substr, int index){
        if(substr.length() == digits.length()){
            res.push_back(substr);
            return;
        }
        for(int i=0; i<key[digits[index]-'0'].length(); i++){
            substr.push_back(key[digits[index]-'0'][i]);
            find_letter(digits, res, substr, index+1);
            substr.pop_back();
        }
        return;
    }
};
