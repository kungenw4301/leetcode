class arithmatic
{
public:
    arithmatic();
    ~arithmatic();

   int add(int a, int b){
        while(b){                   //还有进位的时候就继续加下去
            int sum = a ^ b;     //异或操作被称为不带进位的加法
            int carry = (a & b) << 1;  //与操作刚好是进位，左移1位
            a = sum;
            b = carray;
        }
    }

    //负数就是取反加一
    int negetive(int a){
        return add(~a, 1);
    }

    int substract(int a, int b){
        return add(a, negetive(b));     // a + (-b)
    }

    int positive_multiply(int a, int b){
        int ans = 0;
        while(b){
            if (b & 1)      //如果b是奇数，就要单独加一个a
                ans = add(ans, a);

            a = a<<1;       //a左移一位，相当于a = a*2;
            b = b>>1;       //b右移一位，相当于b = b/2;如果a、b都是偶数，不损失，如果b是奇数，补一个a
        }
        return a;           //最后该乘的乘了，该补的补了，a就是答案了
    }
};
