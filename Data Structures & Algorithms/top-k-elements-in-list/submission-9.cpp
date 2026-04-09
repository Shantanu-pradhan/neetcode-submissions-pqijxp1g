class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int, int>umap;
        vector<pair<int, int>>details;
        //store the result in the map count with the frequency 
        for(int i=0; i<nums.size(); i++){
            umap[nums[i]]++;
        }
        //Store the element and the frequency in the vector with element and frequency 
        for(auto ele=umap.begin(); ele!=umap.end(); ele++){
            details.push_back({ele->second, ele->first});
        }
        sort(details.rbegin(), details.rend());
        for(int i=0; i<k; i++){
            res.push_back(details[i].second);
        }
        return res;
    }
};
