class Implement_strStr
{
public:
    Implement_strStr();
    ~Implement_strStr();
    int strStr(char *haystack, char *needle){
        if (!*needle) return 0; //如果needle都是空的，直接返回0，第0位就开始匹配空
        int p1, p2, p1_advance = 0;
        for(p2 = 1; needle[p2]; ++p2)
            p1_advance++; //提前计算好needl的长度,考虑到'\0'的存在，故从1开始

        /**
         * 如果haystack[p1]为空则说明长度不够，直接停止
         */
        int p_end = 0;
        for (p1=0; haystack[p1_advance]; ++p1_advance)
        {
            int p1_old = p1;  //暂存待测字符串待测的位置，一旦不符合，+1就从头开始
            p2 = 0;

            //都不为空，且相等，则继续下去
            while(haystack[p1] && needle[p2] && haystack[p1] == needle[p2]){
                p1++;
                p2++;
            }

            if(needle[p2] == '\0') return p1_old; //如果needle比较到了最后还是相等，那么就返回索引

            p1 = p1_old + 1; //如果没有相等直到最后，那么haystack往后移一位，
                            //继续比较，直到haystack结束
        }

        //超时了，不知道是为什么
        //原因是之前的for循环没用p1_advance,而用了p1，可能对极其特殊的用例超时了，
        //比如：aaaaaaaab, ab


        return -1;
    }
};
