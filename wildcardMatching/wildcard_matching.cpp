#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch_recursion(string s, string p) {
        char *s_ptr = &s[0];
        char *p_ptr = &p[0];

        return match(s_ptr, p_ptr);
    }

    bool match(const char* s_ptr, const char* p_ptr){

        cout << "recursion_level->" << *s_ptr << endl;
        if(*p_ptr == '*') {
            while(*p_ptr == '*') ++p_ptr;   //跳过连续的 '*'
            if(!*p_ptr) return true;    //连续的'*'，*p == '\0'
        //    string str_s(s_ptr);
        //    string str_p(p_ptr);    //convert char * to string

            //p指针没到末尾，且失配，向后
            //因为前面的一个'*'就能匹配任意多字符，贪婪匹配
            //无法实现，因为str_s/str_p已经生成，不会改变，单独提取一个函数
            while(*s_ptr != '\0' && !match(s_ptr, p_ptr)) ++s_ptr;
            //1.s指针走到最后，退出while，而运行至此，证明*p_ptr == '\0'不成立，否则早返回true了
            //  故，若*s_ptr == '\0'，则p_ptr后面还有，必然全局失配
            //2.若*s_ptr != '\0'，则退出while循环是因为isMatch()为true，那就返回true
            return *s_ptr != '\0';
        }

        else if (*p_ptr == '\0' || *s_ptr == '\0')  // if(!*s_ptr || !p_ptr)
            return *p_ptr == *s_ptr;    //除非两个都为空，否则就是不匹配
        else if (*p_ptr == *s_ptr || *p_ptr == '?')
            return match(++s_ptr, ++p_ptr); //碰到'?'肯定匹配成功

        else return false;
    }

    bool isMatch(string s, string p){
        char *ss = &s[0];
        char *pp = &p[0];
        return check_match(ss, pp);
    }

    //参考：http://blog.csdn.net/kenden23/article/details/17123497
    bool check_match(const char* s, const char* p){
        const char *start_s = NULL, *start_p = NULL; //记录用来回溯的位置
        while(*s){
            if(*p == '?' || *p == *s) ++s, ++p;
            else{
                if(*p == '*'){
                    while(*p == '*') ++p;  //去除连续的'*'
                    if(*p == '\0')  return true;    //整个序列都是'*'
                    start_s = s;    //记录待会儿的回溯地址，从没有'*'处开始匹配
                    start_p = p;    //相当于默认'*'不匹配任何字符的情况下向下匹配
                }else{  //*p不是'?' || '*'，并且两个字符不等
                    if(start_s){    //只要回溯地址不是NULL
                        s = ++start_s;  //认为'*'把失配的字符给匹配了，不管多少个
                        p = start_p;    //恢复上一次的回溯位置，某个失配导致整段跳跃都要'*'匹配
                    }
                    else return false;  //s的回溯位置为NULL
                }
            }
        }

        while(*p == '*') ++p;   //跳过p末端的'*'
        return *s == '\0' && *p == '\0';    //如果p后面还有字符，失配
    }

    //参考：使用switch-case主结构，逻辑清晰，就是 s - 1, p - 1有点绕
    //http://fisherlei.blogspot.sg/2013/01/leetcode-wildcard-matching.html
    bool check_match_ii(const char* s, const char* p){
        bool star = false;   //记录前面有没有遇到'*'
        const char *str, *ptr;  //这两个才是实际用来比较的指针，而s/p在这里被用作了暂存指针
        for(str = s, ptr = p; *str != '\0'; ++str, ++ptr){
            switch(*ptr){
                case '?':
                    break;
                case '*':
                    star = true; //遇到'*'
                    s = str, p = ptr; //使用s,p暂存回溯位置，并且继续试探下去
                    while(*p == '*') ++p; //跳过连续的'*'
                    if(*p == '\0')  return true; //如果p串是连续'*'，必然匹配
                    str = s - 1;
                    ptr = p - 1; //这里s/p后退一位，for循环再加一位，刚好回到比较位置
                    break;
                default:
                    if(*str != *ptr){
                        //如果前面没有'*'，当前字符失配，全局失配
                        if(!star) return false;
                        //s串暂存位置向后一位，视为该失配字符'*'匹配了
                        ++s;    //暂存位置后移一位，即使回溯也应该回溯到此位置
                        str = s - 1;
                        ptr = p - 1;
                    }
            }
        }
        while(*ptr == '*') ++ptr;   //跳过末尾连续的'*'
        return (*ptr == '\0');  //s串处理完了，若是p串还有剩余，且不是'*'，失配
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    string p =  "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";


    //str = "abba";
    //p = "a*c";
    cout << s.isMatch_recursion(str, p) << endl;
    return 0;
}
