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
