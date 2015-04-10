class Solution{
public:
    string intToRoman(int num){
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string roman;
        //贪心策略，每次都找当前可能配的最大值，取商，拼接商数个该最大值
        //从左到右，从大到小，相当于十进制从高到低
        for(int i = 0; num>0; i++){
            int count = num/radix[i];  //当前最大值，如果不大于radix[i]，则后面相当于不会执行
            num %= radix[i];  //取模得到下一个匹配的最大值
            for(;count>0;--count) roman += symbols[i];  //重复拼接count个当前最大值
        }

        return roman;
    }
};
