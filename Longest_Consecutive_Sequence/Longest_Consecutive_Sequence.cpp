#include <iostream>
using namespace std;
class Longest_Consecutive_Sequence
{
public:
	int longestConsecutive(const vector<int> &num){
		unordered_map<int, bool> used;
		for (auto i: num)
		{
			used[i] = false;  //对所有的元素，都设置一个使用标记
		}
		int longest = 0;
		for (auto i: num)    //C++ 11 的类型推导，vector遍历
		{
			if (used[i])
			{
				continue;    //如果访问过，则直接找下一个
			}
			int length = 1;  //如果没有访问过，则最长序列从长度1开始
			used[i] = true;  //元素i访问过
			for (int j=i+1; used.find(j) != used.end(); ++j)
			{				 //从元素i往后找，find(j)只要找到则返回迭代器，找不到则返回end迭代器
				used[j] = true;    //设置访问标志
				++length;
			}
			for (int j = i-1; used.find(j) != used.end(); --j)
			{                //从元素i往前找最长序列，连续则+1，直到断掉
				used[j] = true;
				++length;
			}
			longest = max(longest, length);    //因为这是对每一个元素都找一个最长连续序列
		}										//每次迭代更新longest值

		return longest;
	}

	/*
	*这个算法的思想是思路是在每个点都标记自己的范围，然后检查左右neighbour的范围，
	*看能否合并。按任意顺序访问所有元素后，最终总能将连续的范围合并为一个
	*/
	int longestConsecutive_ii(const vector<int> &num){
		unordered_map<int, int> range;
		int size = num.size();     //避免在for中多次执行num.size()
		int len = 1;			   //初始化最长连续子序列长度为1；
		for (int i = 0; i < size; ++i)
		{
			if (range.find(num[i]) != range.end())    //如果该元素已经在range中有记录则跳过
			{
				continue;
			}
			range[num[i]] = 1;    //没访问过的元素在range中添加，默认单个元素是一个长度为1的子序列
			if (range.find(num[i]-1) != range.end())
			{					  //向前找一个，如果已经有范围，则合并cluster，并尝试更新len；
				len = max(max, mergeCluster(range, num[i]-1, num[i]));
			}
			if (range.find(num[i]+1) != range.end())
			{					  //向后找一个
				len = max(max, mergeCluster(range, num[i], num[i]+1));
			}
		}
		return len == 0 ? 0 : len;
	}

private:
	int mergeCluster(unordered_map<int, int> &map, int left, int right){
		int upper = right + range[right] - 1;		//range这个map传过来，找到最大值
		int lower = left - range[left] + 1;			//找到最小值
		int len = upper - lower + 1;				//由于每次只通过左右邻居来扩大序列长度，故一定连续
		range[right] = len;							//一定要left和right一起更新，这样才标识cluster扩大
		range[left] = len;
		return len;
	}
};
