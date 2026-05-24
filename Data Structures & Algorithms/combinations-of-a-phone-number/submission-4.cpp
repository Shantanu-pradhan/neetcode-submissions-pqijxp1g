class Solution {
public:
    vector<string>maping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string substr;
        if(digits.size() == 0){
            return res;
        }
        find_letter(digits, 0, res, substr);
        return res;
    }
    void find_letter(string &digits, int index, vector<string>&res, string &substr){
        if(substr.size() == digits.size()){
            res.push_back(substr);
            return;
        }
        string sstring = maping[digits[index]-'0'];
        for(int i=0; i < sstring.size(); i++){
            substr.push_back(sstring[i]);
            find_letter(digits, index+1, res, substr);
            substr.pop_back();
        }
        return;
    }
};