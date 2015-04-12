class Solution{
public:
    void nextPermutation(vetcor<int> &num){
        int pivot = num.size()-1;  //找的是最后一个索引
        while(pivot != 0 && num[pivot-1] >= num[pivot]){
            --pivot;     //从右往左，找到第一个降序的元素
        }

        if (pivot == 0)
        {
            //此时，num[0]>num[1]>...,降序
            reverse(num.begin(), num.end());
            return;
        }

        //运行到此，则num[pivot-1]<num[pivot]
        --pivot; //得到枢轴值索引

        //从右至左，找第一个大于num[pivot]的数，恰恰是较大数中最小的一个
        int i;
        for(i = num.size()-1; i>pivot && num[i] <= num[pivot]; --i);
            //do nothing ,运行至此，必有num[i]>num[pivot]
        swap(num[pivot], num[i]); //交换pivot和changeNumber

        //至此，必有 num[pivot]<num[pivot+1],num[i]>num[pivot],
        //交换之后保证num[pivot]之后的元素逆序
        //6,8,7,4,3,2
        //[6],8,[7],4,3,2
        //7,8,6,4,3,2
        //没有交换之前，已经找到pivot和change
        //从右往左，num[pivot+1]->num[change]都大于num[pivot]，因为pivot是第一个降序，
        //change则是从右至左第一个大于pivot的数
        //同时，num[change]->num[end]都是小于pivot的数，也即保证逆序
        reverse(num.begin()+pivot, num.end());  //sort要的是一个Iterator,使用reverse()也可
    }
};
