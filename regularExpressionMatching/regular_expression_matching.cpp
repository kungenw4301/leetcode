class Solution {
public:
    bool isMatch(string s, string p) {
        const char *ss = s.c_str(); //等价于 ss = &s[0];
        const char *pp = p.c_str();
        return match_recursion(ss, pp);
    }

    //分析得很全面了，参考：http://articles.leetcode.com/2011/09/regular-expression-matching.html
    //1.If the next character of p is NOT ‘*’, then it must match the current character of s. Continue pattern matching with the next character of both s and p.
    //2.If the next character of p is ‘*’, then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p… Until we could not match any more characters.
    bool match_recursion(const char *s, const char *p){
        assert(s && p); //s,p不为空
        if(*p == '\0')  return *s == '\0';  //s串还没匹配完，则肯定全局失配

        //下一个char不是'*'，直接匹配就行
        if(*(p + 1) != '*'){
            //两个字符相同，活着*p通配且s串没走到尾
            //递归向下处理
            if(*p == *s || (*p == '.' && *s != '\0')) return match_recursion(s + 1, p + 1);
            else return false; //下一个字符不是'*'，纯字符失配，全局失配
        }

        //上述if一定有返回，故运行至此，说明if条件一定为false，下一个字符是'*'
        while(*p == *s || (*p == '.' && *s != '\0')){
            //关键点，前边已经匹配，从m(s, p + 2)开始向下匹配，默认从'*'一个字符都不匹配开始
            //为什么是(s, p + 2)? p+2 好理解，跳过'*'
            //但为什么是s而不是s+1，因为正则中最糟情况是b*表示0个b，相当于将这个字符吞掉
            //那么while中的*p == *s相当于没有效果，吞掉'*'前面的字符，重新开始
            if(match_recursion(s, p + 2)) return true;
            ++s; //如果(s, p+2)失配了，则++s，认为b*匹配了一个b；一直失配，一直循环直到破坏循环条件
        }

        //到此，下一个肯定是'*'，但是*p既不是'.'也不与*s匹配 活着 *s == '\0'而*p == '.'
        //递归下降处理
        return match_recursion(s, p + 2);
    }

    //参考:http://www.busy-beaver.me/leetcode-10-regular-expression-matching/
    //dp[i+1][j+1]表示s[0..i]是否匹配p[0..j]
    //若p[j] != '*'，dp[i+1][j+1] = (s[i] == p[j] || p[j] == '*') && dp[i][j]
    //若p[j] == '*'
    //*匹配了0个字符。dp[i+1][j+1] = dp[i+1][j-1]（跳过p[j]的*和*前面的p[j-1]。
    //*匹配了1个字符。dp[i+1][j+1] = dp[i+1][j]（跳过p[j]的*)
    //*匹配了2个或2个以上的字符。dp[i+1][j+1] = dp[i][j+1] && (p[j-1] == s[i] || p[j-1] == '.')（s[0..i-1]与p[0..j]匹配，并且p[j-1]与s[i]匹配）
    bool isMatch_DP(string s, string p){
        bool dp[s.size()+1][p.size()+1];
        dp[0][0] = true;    //-1,-1 初始为真
        for(int i = 1; i <= s.size(); ++i){
            dp[i][0] = false;   //s串从左到右，p串长度为0
        }

        //s串为空，p串可以是a******这种连续的'*'，匹配0个字符
        //注意，单独的'*'也是无效的
        for(int j = 1; j <= p.size(); j++){
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2]; //j > 1 是保证存在a*这种序列
        }

        for(int i = 0; i < s.size(); ++i)
            for(int j = 0; j < p.size(); ++j)
                if(p[j] != '*')
                    dp[i + 1][j + 1] = (p[j] == '.' || s[i] == p[j]) && dp[i][j];
                else
                    dp[i + 1][j + 1] = j > 0 && dp[i + 1][j - 1]
                                             || dp[i + 1][j]
                                || j > 0 && (p[j - 1] == '.' || p[j - 1] == s[i]) && dp[i][j+1];

        return dp[s.size()][p.size()]; //s(0, size-1) p(0, size-1)
    }
};
