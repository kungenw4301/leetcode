class sqrt
{
public:
    sqrt();
    ~sqrt();

    /**
     * sqrt(1) = 1
     * sqrt(2) = 1.414=1 <= half(2)
     * sqrt(3) = 1.732=1 <= half(2)
     * sqrt(4) = 2 <= half(2)
     * (x/2)^2 <= x => x(x/4 - 1) <= 0 =>  0<= x <= 4
     * 而就统计学来说，1,2,3,4开根号也不大于half(x)，
     * 于是结论就是：所有int，开放之后的int值不会大于half(x);
     */
    int sqrt(int x){
        int left = 1, right = x / 2;
        int last_mid; //用来记录

        if(x < 2) return x; //sqrt(1) = 1
        while(left <= right){
            const int mid = (left + right) / 2;
            if(x/mid > mid){
                left = mid + 1;
                last_mid = mid;  //为何需要这个mid记录呢？
            }else if (x/mid < mid)
            {
                right = mid - 1;
            }else{
                return mid; //  x/mid == mid
            }
        }

        return last_mid; //如果没有这句，输入
        //2会出错，得到错误值2
        //3出错，得到2
        //这句什么时候有用？如果某次，x/mid > mid
        //                              ==> left = mid + 1
        //                              ==> left > right
        //                              这样就是说二分查找结束
    }
};
