class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        vector<string>substr;
        find_valid_ip(s, res, substr, 0);
        return res;
    }
    void find_valid_ip(string &s, vector<string>&res, vector<string>&substr, int index){
        if(substr.size() == 4){
            if(index == s.size()){
                res.push_back(substr[0]+'.'+substr[1]+'.'+substr[2]+'.'+substr[3]);
                return;
            }
            return;
        }
        for(int i=1; i<=3; i++){
            if(index+i > s.size()){
                break;
            }
            if(stoi(s.substr(index, i)) > 255){
                break;
            }
            string part = s.substr(index, i);
            if(part.size() > 1 && part[0] == '0'){
                break;
            }
            substr.push_back(part);
            find_valid_ip(s, res, substr, index+i);
            substr.pop_back();
        }
    }
};