#include <iostream>
using namespace std;
class TwoSum
{
public:
	/*
	*使用一个hash，存储数值对应的下标，也就是和数组反过来
	*/
	vector<int> twoSum(vector<int> &numbers, int target){
		unordered_map<int, int> mapping;
		vector<int> result;
		int n = numbers.size();
		for (int i = 0; i < n; ++i)
		{
			mapping[numbers[i]] = i;    //存储某个数对应的下标
		}
		for (int i = 0; i < n; ++i)
		{
			const int gap = target - numbers[i];    //算出相配对的数值
			if (mapping.find(gap) != mapping.end() && mapping[gap] > i)    //配对数字在hash中，且一前一后
			{
				result.push_back(i+1);    //对每个i，若配对则记录i+1，不是以0开始，故+1
				result.push_back(mapping[gap]+1);    //配对的数字的下标
				break;
			}
		}
		return result;
	}
};
