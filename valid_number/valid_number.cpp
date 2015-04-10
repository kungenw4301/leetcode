class Solution{
public:
    //偷懒的方式，使用strtod()函数，其实这题真正的解法应该是使用DFA
    bool isNumber(string str){
        char* endptr;
        strtod(str, &endptr);
        //自动去空格，考虑符号，最终取出第一个float并返回，
        //&endptr指示下一个字符的位置
        if(endptr == str) return false; //根本没有合法的数字
        for(; *endptr; enptr++)
            if(!isspace(*endptr)) return false; //如果去除数字后后面是连续空格则一直执行


        return true; //进行到此，说明取出数字之后全是连续空格
    }
};
