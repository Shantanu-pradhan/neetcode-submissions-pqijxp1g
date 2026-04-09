class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;
        for(string s:strs){
            string ss = s;
            sort(ss.begin(), ss.end());
            umap[ss].push_back(s);
        }
        vector<vector<string>>res;
        for(auto pair:umap){
            res.push_back(pair.second);
        }
        return res;
    }
};
