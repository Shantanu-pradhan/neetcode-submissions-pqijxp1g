class Solution {
public:
vector<string>maping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.length() == 0){
            return res;
        }
        find_comb(digits, 0, "", res);
        return res;
    }
    void find_comb(string digits, int index, string substr, vector<string>&res){
        if(substr.length() == digits.length()){
            res.push_back(substr);
            return;
        }
        int num = digits[index] - '0';
        string sstring = maping[num];
        for(int i=0; i<sstring.length(); i++){
            substr+=sstring[i];
            find_comb(digits, index+1, substr, res);
            substr.pop_back();
        }
        return;
    }
};
