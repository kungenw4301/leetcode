#include <iostream>
using namespace std;
class Next_N{
public:
    //找出大于n的最小的数，这个数要和n有相同的为1的位


    //现在从右往左数的一系列连续的1，都被进位给清除掉了，要把剩余的1给补上
    //但是补在哪里才能使得这个数刚好是比n大的呢？
    //在n最右边的1上加1保证这个数肯定大于n，在n最右边补上相应的缺少的1能保证补的1带来的值最小
    //如何严格证明在从右数起来的第一个1之前+1都不能满足条件呢？
    //这样考虑：10001000，如果在右数第一个1之前任意位置（肯定为0）加上1，
    //那么就要挪去一个1才能保证1的bit数量相等，挪的1肯定在补的1左边，故减掉的就比补上的多
    //这样就会导致这个新的数小于n

    //n和t做异或，将把n从右数的连续的1保留下来，再保留那个进位得来的1，
    //同样得到一个连续的1的串，这个串的特征是：原来从右数有k个连续的1，现在有k+1个
    //将这个串右移到最右边，这样再右移2位，就能将k+1变成k-1个连续的最右的1，加上刚才进位的1
    //就保证有k个1了，而前面的1都没有动过，就保证1的个数相等了
    int find_next_n(int n){
        int x = n & -n; //只保留最右边的那个1，其他全部清零
        int t = n + x;  //在最右边那个1上再加1，这就保证一定比n大
        int serail = n ^ t;
        int right = serail / x; //因为x只保留了n最右边的1，故一定是2的幂，二进制相除，刚好将n^(n+n&(-n))右移
        int addBits = right >> 2; //从k+1个连续的1串变成k-1个连续的1串
        int result = t | addBits; //将n+n&(-n)与 n^(n+n&(-n))/(n&(-n))>>2
    }

    int find_next_n_ex(int n){
        return (n+(n&(-n))) | ((n^(n+(n&(-n))))/ (n&(-n)) >> 2);
    }
};

int main(int argc, char const *argv[])
{
    Next_N s;
    int next_n = s.find_next_n_ex(78);
    cout << "next_n_ex->" << next_n << endl;
    cout << "next_n->" << s.find_next_n(15) << endl;

    cout << "next_n->" << s.find_next_n(78) << endl;
    return 0;
}
