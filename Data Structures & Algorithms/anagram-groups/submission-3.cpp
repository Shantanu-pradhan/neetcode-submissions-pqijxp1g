class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mstr;
        vector<vector<string>>result;
        for(const auto&it:strs){
            vector<int>count(26, 0);
            for(char c:it){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i<26; i++){
                key+=','+to_string(count[i]);
            }
            mstr[key].push_back(it);
        }
        for(auto &pair:mstr){
            result.push_back(pair.second);
        }
        return result;
    }
};
