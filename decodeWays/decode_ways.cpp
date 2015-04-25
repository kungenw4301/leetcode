class Solution
{
public:
    //动态规划问题，每次只能挑选其中的1个或2个digit来解码，并且digit表示的数字介于1~26之间
    //不用关心解码得到的内容是什么
    //Transformation function as:
    //  Count[i] = Count[i-1]  if S[i-1] is a valid char
    //      or   = Count[i-1]+ Count[i-2]  if S[i-1] and S[i-2] together is still a valid char.
    //这种写法比较难理解,反直觉
    int numDecodings(string s){
        if(s.empty() || s[0] == '0') return 0;   //起始条件非法
        int prev = 0;   //对应s[i-1]
        int cur = 1;    //对应s[i]

        for (int i = 1; i <= s.size(); ++i)
        {
            if(s[i-1] == '0') cur = 0;  //f(n) += f(n-1)

            if(i < 2 || !(s[i-2] == '1' ||
                            (s[i-2] == '2' && s[i-1] <= '6'))){
                //后面这个条件是要求两位数字的情况下，10<= num <=26
                prev = 0;   //不满足条件， f(n) = f(n-1);满足则：f(n) = f(n-1) + f(n-2)
            }

            int tmp = cur;
            cur = prev + cur;
            prev = tmp;
        }

        return cur;
    }
};
