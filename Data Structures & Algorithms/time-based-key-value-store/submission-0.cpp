class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>>umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        string result = "";
        auto &val = umap[key];
        int left = 0;
        int right = val.size()-1;
        while(left <= right){
            int mid = left+(right-left)/2;
            if(timestamp >= val[mid].first){
                result = val[mid].second;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return result;
    }
};
