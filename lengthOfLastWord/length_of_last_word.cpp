#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
/**
    1. char *ch; 直接使用 while(*s)就能判断是不是等于'\0';
    2. if(*ch++ != ' ') 相当于先后执行：

        1. *ch != ' ';
        2. ch++;
        3. 而且是两句都会执行，
        4. 后果是无论 *ch != ' '成立与否，ch都会往后移动
        5. 副作用是执行这句之后的else if中的ch已经不是if中的ch了

    3. if...else if 的语义就是：if为false才执行else if，这一点很基础，但是却很容易忽略；
    4. 造成的后果就是"b a c"中，每一次判断了是空格，要归零的时候，执行到esle if都是false，ch跑掉了；
    5. 所以这段程序累加了三个间隔的字符；
**/
    int lengthOfLastWord_wrong(string s) {
        char* ch = &s[0];
        int len = 0;
        while(*ch){
            if(*ch++ != ' ')
                len++;
            else if(*ch && *ch == ' ') //仅在if条件为false时执行
                len = 0;    //错误：if为false时执行本行，此时已经ch++过，不是if中的ch了

            //test
            cout << "len: " << len << endl;
            cout << *ch << endl;
        }
        return len;
    }

    int lengthOfLastWord(string s) {
        char* ch = &s[0];
        int len = 0;

        //这两行很重要，去除末尾的连续空格，否则遇到"b a "这种末尾空格的就会清零
        char* end = &s[s.size()-1];
        while(*end == ' ') *end-- = '\0';

        while(*ch){
            if(*ch != ' ')
                len++;
            else if(*ch == ' ') //仅在if条件为false时执行
                len = 0;    //错误：if为false时执行本行，此时已经ch++过，不是if中的ch了

            //test
            cout << "len: " << len << endl;
            cout << *ch << endl;

            ch++;   //不管是不是空格，每次都后移指针
        }
        return len;
    }

    //这种也是正确的，但是上面的更加简洁
    //来源：http://leetcode.tanglei.name/content/string/Length-of-Last-Word.html
    int lengthOfLastWord_ii(string s)
    {
        char* ch = &s[0];
        if(ch == NULL || *ch == '\0') return 0;
        while(*ch != '\0' && *ch == ' ') ch++;
        if(*ch == '\0') return 0;
        int len = 0;
        while(*ch != '\0')
        {
            if(*ch != ' ')
                len++;
            else
            {
                while(*ch == ' ')
                    ch++;
                if(*ch == '\0')
                    break;
                len = 1; //*s != ' '
            }
            ch++;
        }
        return len;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "b a c";
    //str = ""; //这里能够证明while(*ch)根本没进入程序，也就是说while会判断*ch是不是'\0'
    cout << s.lengthOfLastWord(str) << endl;
    str = "b a ";
    cout << s.lengthOfLastWord(str) << endl;
    return 0;
}

#include <iostream>using namespace std;

int main(){
  const char *str = "apple\0";
  const char *it = str;
  while(*it++)
  {
    cout << *it << '_';
  }}

//output:
//  p_p_l_e__
//Notice the missing first character and the extra _ underscore at the end
////


//Binary   Oct  Dec    Hex    Abbr    Unicode  Control char  C Escape code   Name
//0000000  000  0      00     NUL     ␀       ^@            \0              Null character
//https://en.wikipedia.org/wiki/ASCII#ASCII_control_code_chart
