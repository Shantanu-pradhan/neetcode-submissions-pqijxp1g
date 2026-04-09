class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;
        for(auto& str: strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(str);
        }
        vector<vector<string>>res;
        for(auto& pair:umap){
            res.push_back(pair.second);
        }
        return res;
    }
};
