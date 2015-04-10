class pow
{
public:
    pow();
    ~pow();

    double pow(double x, int n){
        if (n < 0)
        {
            return 1.0 / power(x, -n);  //如果指数是负数，处理
        }

        else return power(x, n);
    }

private:
    double power(double x, int n){
        if (n == 0)
        {
            return 1;
        }
        double half = power(x, n/2);
        if (n % 2 == 0)
        {
            return half*half;
        }else return half*half*x; //奇数次，最后单独乘一次
    }
};
