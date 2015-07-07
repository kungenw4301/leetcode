class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int profit = 0; //利润，差价
        int cur_min = prices[0]; //开始以第一个价格为最低价
        for(int i = 1; i < prices.size(); ++i){
            profit = max(profit, prices[i] - cur_min); //尝试更新最高利润
            cur_min = min(cur_min, prices[i]); //如果股价比记录的最低股价低，更新
        }

        return profit;
    }
};
