class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>card;
        for(int i=0; i<position.size(); i++){
            card.push_back({position[i], speed[i]});
        }
        sort(card.rbegin(), card.rend());
        vector<double>stack;
        for(auto pair: card){
            stack.push_back((double(target-pair.first))/pair.second);
            if(stack.size() >=2 && (stack.back() <= stack[stack.size()-2])){
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
