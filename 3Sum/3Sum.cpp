#include <iostream>
using namespace std;
class 3Sum
{
public:
	/*先排序，然后左右夹逼，复杂度 O(n2)。
	*这个方法可以推广到 k-sum，先排序，然后做 k-2 次循环，
	*在最内层循环左右夹逼，时间复杂度是 O(max(n log n, n^(k − 1))。
	*/
	vector<vector<int>> threeSum(vector<int> &num){
		vector<vector<int>> result;
		if (num.size() < 3)
		{
			return result;
		}
		sort(num.begin(), num.end());
		const int target = 0;

		auto last = num.end();
		for (auto a = num.begin(); a<prev(last, 2); ++a) //从头开始，直到最后三个元素
		{
			auto b = next(a);	//a的下一个
			auto c = prev(last);//倒数第一个元素
			if (a>num.begin()&& *a == *(a-1) )
			{
				continue;
			}
			while(b<c){
				if (*a + *b + *c < target) //排序后，最后一个最大，固定a，则调整b
				{
					++b;
					while(*b == *(b-1) && b<c) ++b; //先加，加了之后如果等与前一个则跳
				}else if (*a + *b + *c > target) //大了，调整c
				{
					--c;
					while(*c == *(c+1) && b<c) --c; //先减，前等于后则跳
				}else{
					result.push_back({*a, *b, *c});  //相等，收集一组符合的元素
					++b;    //移动b、c，继续找下一组
					--c;
					while(*b == *(b-1) && *c == *(c+1) && b < c) ++b; //加了的和前比，减了的和后比
				}
			}
		}
		sort(result.begin(), result.end());
		//unique()删除vector中相邻重复的元素，全都向前靠拢，剩余位置是未知状态；
		//erase删除range范围内的元素
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};
