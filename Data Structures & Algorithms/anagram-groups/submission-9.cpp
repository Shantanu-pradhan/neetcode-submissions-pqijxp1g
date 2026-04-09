class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;
        vector<vector<string>>vres;
        for(string str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }
        for(auto pair:umap){
            vres.push_back(pair.second);
        }
        return vres;
    }
};
