class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>>sstack;
        int temp = 0;
        for(int i=0; i < temperatures.size(); i++){
            temp = temperatures[i];
            while(!sstack.empty() && (temp > sstack.top().first)){
                res[sstack.top().second] = i - sstack.top().second;
                sstack.pop();
                //auto pair = sstack.top();
                //sstack.pop();
                //res[pair.second] = i - pair.second;
            }
            sstack.push({temp, i});
        }
        return res;
    }
};
