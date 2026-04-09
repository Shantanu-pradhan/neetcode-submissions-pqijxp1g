class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        vector<vector<string>>result;
        for(const auto & s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            res[t].push_back(s);
        }
        for(auto &pair : res){
            result.push_back(pair.second);
        }
        return result;
    }
};
