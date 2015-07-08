class Solution {
public:
    //设状态 f(i)，表示区间 [0, i](0 <= i <= n - 1) 的最大利润，状态 g(i)，表示区间
    //[i, n - 1](0 <= i <= n-1) 的最大利润，则最终答案为 max{f(i) + g(i) }, 0 <= i <= n-1。
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0; //过空集合
        const int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for(int i = 1, valley = prices[0]; i < n; ++i){
            valley = min(valley, prices[i]); //低进高出，所以第一次交易先找valley
            f[i] = max(f[i - 1], prices[i] - valley);
        }

        for(int i = n - 2, peak = prices[n - 1]; i >= 0; --i){
            peak = max(peak, prices[i]); //第二次交易，低进高出，从后往前，当然先找后面的最高价
            g[i] = max(g[i + 1], peak - prices[i]); //从后往前，前面的以来后面的
        }

        int max_profit = 0;
        for(int i = 0; i < n; ++i){
            max_profit = max(max_profit, f[i] + g[i]); //遍历每一个切分点，寻找两次交易的最大值
        }

        return max_profit;
    }
};
