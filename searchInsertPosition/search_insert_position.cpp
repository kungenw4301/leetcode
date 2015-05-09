class Solution{
public:
    int searchInsert(vector<int> &nums, int target){
        return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value){
        ForwardIterator mid;
        typename iterator_traits<ForwardIterator>::difference_type count, step;

        count = distance(begin, end);   //[beg, end)，数组长度，左开右闭正好count个
        while(count > 0){
            mid = beg;
            step = count / 2;   //找到middle位置需要往后++的次数
            advance(mid, step); //++mid step次
            if(*mid < value){
                beg = ++mid;    //[beg, mid]废弃，[mid+1, mid+1+count)保留
                count -= (step + 1);    //只保留mid+1及后面的,一共count个，去掉step,去掉mid
            }else
                count = step;   //beg不变，[beg, beg+count),即[beg, beg+step-1]共step个
                                //若*mid > target，保留从beg开始，共step个，连mid都去掉
                                //若*mid == target,同样，因为前面可能还有==value的，找第一个
                                //相当于留下[beg, mid),正好step个
        }
        return beg; //最后一定是找到第一个等于value的，若不存在，找到第一个大于value的位置
        //总结：mid无论和target大小关系如何，都不会保留，保留的数组要么是mid前一半，要么是mid后一半
        //出口是count == 0，此时beg一定指向等于target位置，或者第一个大于target的位置
    }
};
