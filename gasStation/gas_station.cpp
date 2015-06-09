class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        for(int i = 0; i < gas.size(); ++i){
            diff.push_back(gas[i] - cost[i]);
        }

        int leftGas = 0, sumCost = 0, start = 0;
        for(int i = 0; i < gas.size(); ++i){
            leftGas += diff[i];     //累计剩余油量
            sumCost += diff[i];

            if(sumCost < 0){    //解k在这样的位置：0~(k-1)和为负，k~n和为正
                sumCost = 0;    //淘汰的每一段都是sum为负，开不动，就得继续往下
                start = i + 1;  //加到i处都是负值，重置sum，计数前移
            }

        }

        //leftGas >= 0 ，肯定有解，题目保证有唯一解，淘汰了i~(start-1)这一段，结合本条件，得解
        if(leftGas < 0) return -1;  //全局累计都是负值，肯定不能完成
        return start;
    }
};
