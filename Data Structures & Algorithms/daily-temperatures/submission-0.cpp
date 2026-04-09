class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>>sstack;
        int num=0;
        for(int i=0; i<temperatures.size(); i++){
            num = temperatures[i];
            while(!sstack.empty() && num>sstack.top().first){
                auto pair=sstack.top();
                sstack.pop();
                res[pair.second] = i-pair.second;
            }
            sstack.push({num, i});
        }
        return res;
    }
};
