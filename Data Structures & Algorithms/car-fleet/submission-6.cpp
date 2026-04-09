class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cdetails;
        for(int i=0; i<position.size(); i++){
            cdetails.push_back({position[i], speed[i]});
        }
        sort(cdetails.rbegin(), cdetails.rend());
        vector<double>fleet;
        for(auto pair:cdetails){
            fleet.push_back((double(target-pair.first))/pair.second);
            if(fleet.size() >=2 && fleet.back() <= fleet[fleet.size()-2]){
                fleet.pop_back();
            }
        }
        return fleet.size();
    }
};
