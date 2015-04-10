class Solution{
public:
    //一，羅馬數字共有7個，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。
    //二，在較大的羅馬數字的右邊記上較小的羅馬數字，表示大數字加小數字，例如：VI（6），VIII（8），
    //LV（55=50 + 5），LX（60=50 + 10）
    //三，在較大的羅馬數字的左邊記上較小的羅馬數字，表示大數字减小數字，例如：IX（9），XL（40=50 - 10），XC（90=100 - 10）
    //四，左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV。
    //五，左減時不可跨越一個位數。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i>0 && charToInt(s[i]) > charToInt(s[i-1])){
                result += charToInt(s[i]) - 2*charToInt(s[i-1]); //比如XL = x+L-X-X,不加反减差距变成两倍
            }else{
                result += charToInt(s[i]); //如果后一位比前一位大，直接加
            }
        }
        return result;
    }

    int charToInt(const char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
};
