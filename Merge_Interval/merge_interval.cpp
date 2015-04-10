#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
  };


class Merge_interval
{
public:

    vector<Interval> merge(vector<Interval> &intervals){
        vector<Interval> result;
        if(intervals.empty()) return intervals;
        result.push_back(intervals[0]);
        for(int i = 1; i< intervals.size(); i++)
        {
             result = insert(result, intervals[i]); //原来问题出在这里，不接的话就调用消失
             print_vector(result, "i->");           //因为返回的是另外一个vector
        }
        return result;
    }

/*
    //复用 insert_interval.cpp 中的插入算法
    vector<Interval> insert_wrong(vector<Interval> &intervals, Interval newInterval){
        vector<Interval> result;
        vector<Interval>::iterator it = intervals.begin();
        for(; it != intervals.end() && it->end < newInterval.start ; it++){
            result.push_back(*it);
        }

        if(it == intervals.end()){
            result.push_back(newInterval); //找到最后了，start还是大，加在末尾
        }

        //另一种情况，某个element的end > newInterval.start，定位到头的位置了
        //直接比较得到新的start
        newInterval.start = min(it->start, newInterval.start);

        //开始找尾部的位置
        //element的end > neweInterval.end，则覆盖，合并，真正的merge
        for(; it != intervals.end() && it->start <= newInterval.end; ++it){
            newInterval.end = max(it->end, newInterval.end);
        }

        //运行到这一步有两种可能
        //1. newInterval.end 一直merge到了vector末尾这个元素
        //2. it->start > newInterval.end ，这个merge就结束了
        //相当于是找到某个位置，it->start >= newInterval.end

        result.push_back(newInterval);

        //对于第二种情况，那就是 it->start > newInterval.end
        //此时后面还有剩余的数，直接加入结果
        for(;it != intervals.end(); ++it){
            result.push_back(*it);
        }

        return result;

    }
*/

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    result.push_back(newInterval); //[1,5]

    print_vector(result, "result");


    print_vector(intervals, "intervals");
    for(int i=0; i< intervals.size(); i++)
    {
        Interval newInt = result.back(); //[1,5]
        result.pop_back();//[]
        print_vector(result, "pop_back");
        Interval* cur = &intervals[i]; //[1,4]
        if(cur->end < newInt.start)
        {
          result.push_back(*cur);
          result.push_back(newInt);
          print_vector(result, "87");
        }
        else if(cur->start > newInt.end)
        {
          result.push_back(newInt);
          result.push_back(*cur);
          print_vector(result, "93");
        }
        else
        {
          newInt.start = min(cur->start, newInt.start);
          newInt.end = max(cur->end, newInt.end);
          result.push_back(newInt);
          print_vector(result, "100");
        }
    }
    print_vector(result, "return");
    return result;

}
    void print_vector(vector<Interval> &intervals, string str){
        cout << str << "->";
        for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end(); ++i)
        {
            std::cout<<"["<< i->start <<","<<i->end<<"]"<<",";
        }
        cout<<endl;
    }

};

/*
    vector<Interval> merge(vector<Interval> &intervals) {
       vector<Interval> result;
       for(int i =0; i< intervals.size(); i++)
       {
            insert(result, intervals[i]);
       }
       return result;
    }
    void insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while(it!= intervals.end())
        {
             if(newInterval.end<it->start)
             {
                  intervals.insert(it, newInterval);
                  return;
             }
             else if(newInterval.start > it->end)
             {
                  it++;
                  continue;
             }
             else
             {
                  newInterval.start = min(newInterval.start, it->start);
                  newInterval.end = max(newInterval.end, it->end);
                  it =intervals.erase(it);
             }
        }
        intervals.insert(intervals.end(), newInterval);
    }
*/


int main(int argc, char const *argv[])
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,4));
    intervals.push_back(Interval(1,5));
    for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end(); ++i)
    {
        std::cout<<"["<< i->start <<","<<i->end<<"]"<<",";
    }
    cout<<endl;
    Merge_interval m;
    intervals = m.merge(intervals);

    m.print_vector(intervals, "final");
    cin.get();
    return 0;
}

