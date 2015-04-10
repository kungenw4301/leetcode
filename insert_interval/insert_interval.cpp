class insert_interval
{
public:
    insert_interval();
    ~insert_interval();
    /**
     * struct Interval{
     *     int start;
     *     int end;
     *     Interval(): start(0), end(0){ }
     *     Interval(int s, int e) start(s), end(e) { }
     * }
     */
    vector<Interval> insert_wrong(vector<Interval> &intervals, Interval newInterval){
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end()){
            if(newInterval.end < it->start){ //在所有区间最左边，加入到头
                intervals.insert(it, newInterval); //插入it前还是it后面呢？before position
                return intervals;
            }
            else if(newInterval.start > it->end ){
                it++;   //newInterval区间在it区间之外
                continue; //换成下一个区间，继续分辨
            }
            else{
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end); //merge新区间和overlap区间
                intervals.erase(it); //擦除掉overlap区间
            }
        }
         //为什么放在这里呢？需要全部遍历一次
         //否则不知道merge之后的overlap会不会覆盖到最后一个区间
        intervals.insert(intervals.end(), newInterval); //超时
        return intervals;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
        vector<Interval> result;
        int i = 0;
        int n = intervals.size(); //求出size，避免每次调用
        vector<Interval>::iterator it = intervals.begin();

        for (; it != intervals.end() && it->end < newInterval.start; ++it)
        {
            result.push_back(*it);
        }

        if(it == intervals.end()){
            result.push_back(newInterval);
            return result;  //一直到最后新区间都没有被overlap
        }

        //运行到这里说明it-> < newInterval.start 不成立，开始merge
        //注意，指针取数据用 it->start ，对象取数据用 obj.start
        newInterval.start = min(it->start, newInterval.start);

        for (; it != intervals.end() && it->start <= newInterval.end; ++it)
        {
            //现在newInterval的头固定好了，找尾部
            // it->start < nv.end && it->start < it->start ，开始merge
            newInterval.end = max(it->end, newInterval.end);
        }
        //运行到这一步有两种可能
        //1. newInterval.end 一致merge到了vector末尾这个元素
        //2. it->start > newInterval.end ，这个merge就结束了
        //相当于是找到某个位置，it->start >= newInterval.end
        result.push_back(newInterval);

        for (; it != .end(); ++it)
        {
            result.push_back(it);
        }

        return result;

    }

     vector<Interval> insert_while(vector<Interval> &intervals, Interval newInterval){
        vector<Interval> result;
        vector<Interval>::iterator it = intervals.begin();


        while(it != intervals.end()){
            if(it->end < newInterval.start){
                result.push_back(*it);
                ++it;
                continue;
            }

            if(it->end >= newInterval.start){
                newInterval.start = min(it->start, newInterval.start);
            }

            if(it->start < newInterval.end){
                newInterval.end = max(it->end, newInterval.end);
                it++;
                continue;
            }

            result.push_back(newInterval);


        }




        for (; it != intervals.end() && it->end < newInterval.start; ++it)
        {
            result.push_back(*it);
        }

        if(it == intervals.end()){
            result.push_back(newInterval);
            return result;  //一直到最后新区间都没有被overlap
        }

        //运行到这里说明it->end < newInterval.start 不成立，开始merge
        //注意，指针取数据用 it->start ，对象取数据用 obj.start
        newInterval.start = min(it->start, newInterval.start);

        for (; it != intervals.end() && it->start <= newInterval.end; ++it)
        {
            //现在newInterval的头固定好了，找尾部
            // it->start < nv.end && it->start < it->start ，开始merge
            newInterval.end = max(it->end, newInterval.end);
        }
        //运行到这一步有两种可能
        //1. newInterval.end 一致merge到了vector末尾这个元素
        //2. it->start > newInterval.end ，这个merge就结束了
        //相当于是找到某个位置，it->start >= newInterval.end
        result.push_back(newInterval);

        for (; it != intervals.end(); ++it)
        {
            result.push_back(*it);
        }

        return result;

    }

//题目默认整个intervals是有序的，且根据用例来说是unique的
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    result.push_back(newInterval);  //第一个元素直接加入
    for(int i=0; i< intervals.size(); i++)  //每次获得最后一个元素，计算重叠
    {
        Interval newInt = result.back();  //获得最后一个元素，记录
        result.pop_back();                //pop最后一个元素
        Interval* cur = &intervals[i];     //获得当前指针指向的元素
        if(cur->end < newInt.start)         //无重叠，待插区间在当前区间之后
        {                                   //先插入当前区间，再插入待插区间，由小到大
          result.push_back(*cur);
          result.push_back(newInt);
        }
        else if(cur->start > newInt.end)    //无重叠，当前区间在后，待插区间在前
        {                                   //先插入待插区间，再插入当前区间，小到大
          result.push_back(newInt);
          result.push_back(*cur);
        }
        else                                //有重叠，找出新的边界，每次只合并两个区间
        {
          newInt.start = min(cur->start, newInt.start);
          newInt.end = max(cur->end, newInt.end);
          result.push_back(newInt);
        }
    }
    return result;

    }
};
