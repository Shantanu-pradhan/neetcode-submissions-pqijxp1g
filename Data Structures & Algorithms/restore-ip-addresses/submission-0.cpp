class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        vector<string>substr;
        find_ip(s, 0, substr, res);
        return res;
    }
    void find_ip(string s, int index, vector<string>&substr, vector<string>&res){
        if(substr.size() == 4){
            if(index == s.size()){
                res.push_back(join(substr));
            }
            return;
        }
        for(int len = 1; len<=3; len++){
            if(index+len > s.size()){
                break;
            }
            if(stoi(s.substr(index, len)) > 255){
                continue;
            }
            string part = s.substr(index, len);
            if(part.length() > 1 && part[0] == '0'){
                continue;
            }
            substr.push_back(part);
            find_ip(s, len+index, substr, res);
            substr.pop_back();
        }
    }
    string join(vector<string>&substr){
        string res = substr[0]+'.'+substr[1]+'.'+substr[2]+'.'+substr[3];
        return res;
    }
};