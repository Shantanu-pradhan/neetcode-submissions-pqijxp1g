class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>umap;
        for(auto s:strs){
            string str = s;
            sort(str.begin(), str.end());
            umap[str].push_back(s);
        }
        for(auto pair: umap){
            res.push_back(pair.second);
        }
        return res;
    }
};
