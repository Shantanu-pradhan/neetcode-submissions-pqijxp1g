class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int plen = prices.size();
        int start = 0;
        int end=1;
        int max_profit = prices[end] - prices[start];
        for(int end=1; end<plen; end++){
            if(prices[start] > prices[end]){
                start = end;
            } else {
                if((prices[end] - prices[start]) > max_profit){
                    max_profit = prices[end] - prices[start];
                }
            }
        }
        return max_profit < 0 ? 0:max_profit;
    }
};
