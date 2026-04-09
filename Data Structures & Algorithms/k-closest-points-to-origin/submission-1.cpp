class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>>pq;
        vector<vector<int>>res;
        for(auto point:points){
            int dist = point[0]*point[0]+point[1]*point[1];
            pq.push({dist,{point[0], point[1]}});
            if(pq.size() > k){
                pq.pop();
            }
        }
        for(int i=0; i<k; i++){
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};
