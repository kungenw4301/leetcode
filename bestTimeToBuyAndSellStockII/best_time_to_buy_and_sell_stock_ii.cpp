class Solution {
public:
    //贪心法，低进高出，把所有正的价格差价相加起来。
    //把原始价格序列变成差分序列，本题也可以做是最大 m 子段和，m = 数组长度。
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int diff = 0;
        for(int i = 1; i < prices.size(); ++i){
            diff = prices[i] - prices[i - 1]; //计算每一天的和前一天的差价；
            if(diff > 0) sum += diff; //累计所有为正的差价
        }
        return sum;
    }
};
