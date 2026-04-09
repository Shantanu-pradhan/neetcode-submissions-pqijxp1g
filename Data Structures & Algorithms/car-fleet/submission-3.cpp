class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>location;
        vector<double>result;
        if(position.size() == 0){
            return 0;
        }
        if(position.size() == 1){
            return 1;
        }
        for(int i=0; i<position.size(); i++){
            location.push_back({position[i], speed[i]});
        }
        sort(location.rbegin(), location.rend());
        for(int i=0; i<position.size(); i++){
            result.push_back(double((target - location[i].first))/(location[i].second));
            if(result.size() >=2 && result.back() <= result[result.size()-2]) {
                result.pop_back();
            }
        }
        return result.size();
    }
};
