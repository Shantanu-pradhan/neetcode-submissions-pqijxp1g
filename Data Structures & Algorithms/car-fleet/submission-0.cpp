class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>carDetails;
        for(int i=0; i<position.size(); i++){
            carDetails.push_back({position[i], speed[i]});
        }
        sort(carDetails.rbegin(), carDetails.rend());
        vector<double>totFleet;
        for(int i=0; i<carDetails.size(); i++){
            totFleet.push_back(double(target-carDetails[i].first)/carDetails[i].second);
            if(totFleet.size()>=2 && (totFleet.back() <= totFleet[totFleet.size()-2])){
                totFleet.pop_back();
            }
        }
        return totFleet.size();
    }
};
