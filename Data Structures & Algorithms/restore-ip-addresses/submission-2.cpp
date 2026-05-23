class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        vector<string>substr;
        if(s.size() > 12){
            return res;;
        }
        find_ip(s, res, substr, 0);
        return res;
    }
    void find_ip(string &s, vector<string>&res, vector<string>&substr, int index){
        if(substr.size() == 4){
            if(index == s.size()){
                res.push_back(substr[0]+'.'+substr[1]+'.'+substr[2]+'.'+substr[3]);
                return;
            }
            return;
        }
        for(int length = 1; length <= 3; length++){
            if(index+length > s.size()){
                break;
            }
            if(stoi(s.substr(index, length)) > 255){
                break;
            }
            string part = s.substr(index, length);
            if(part.length() > 1 && part[0] == '0'){
                break;
            }
            substr.push_back(part);
            find_ip(s, res, substr, index+length);
            substr.pop_back();
        }
        return;
    }
};