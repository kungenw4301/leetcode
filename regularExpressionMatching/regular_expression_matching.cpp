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
};
