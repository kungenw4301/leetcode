class Solution {
public:
//其实我们可以发现字符串中永远只会出现1,2,3这三个字符，
//假设第k个字符串中出现了4，那么第k-1个字符串必定有四个相同的字符连续出现，
//假设这个字符为1，则第k-1个字符串为x1111y。第k-1个字符串是第k-2个字符串的读法，
//即第k-2个字符串可以读为“x个1,1个1,1个y” 或者“*个x,1个1,1个1,y个*”，
//这两种读法分别可以合并成“x+1个1,1个y” 和 “*个x，2个1，y个*”，
//代表的字符串分别是“(x+1)11y” 和 "x21y"，
//即k-1个字符串为“(x+1)11y” 或 "x21y"，不可能为“x1111y”.
    string countAndSay(int n) {
        if(n < 1) return "";    //n太小，返回空串
        string prev = "1";  //从长度为1的序列开始
        for (int i = 2; i <= n; ++i)
        {
            char curChar = prev[0]; //当前字符从上一个串的开头算起
            int times = 1;  //计数器初始化为1
            string tmpStr;  //存储prev生成的串
            prev.push_back('#');    //如果不加这个边界符，则最后一串相同字符不能转化成times个curChar,处理完最后一个char，就会j == prev.size()而退出
            for(int j = 1; j < prev.size(); ++j){   //第0个字符已经计数了
                if(prev[j] == curChar)
                    times++;    //累计相同的字符
                else{
                    tmpStr += to_string(times); //一个字符计数完毕，times个curChar
                    tmpStr.push_back(curChar);
                    curChar = prev[j];  //要开始下个字符，curChar存储待比较字符
                    times = 1;  //初始化这次变化的字符prev[k]的次数为1
                }
            }

            prev = tmpStr;  //第i个串生成了第i+1个串，存储起来，用于作为第i+2个的prev
        }

        return prev;
    }
};
