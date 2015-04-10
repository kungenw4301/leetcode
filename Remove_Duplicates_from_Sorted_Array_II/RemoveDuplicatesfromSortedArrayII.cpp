#include <iostream>
using namespace std;

class RemoveDuplicatesfromSortedArrayII
{
public:
	int removeDuplicates(int A[], int n){
		if (A == NULL || n == 0)
		{
			return 0;
		}
		int idx = 0, count = 0;
		for (int i = 0; i < n; ++i)
		{
			//第0个元素不算在内
			//由于是有序的数组，所以重复的必然连续
			if (i > 0 && A[i] == A[i - 1])
			{
				count++ ;

				//计数超过则进入下一个for循环，继续累积计数或者重置计数
				//如果下面一次遇到的是新数则重置技术并填idx，如果下面还是重复则继续计数
				//如果下面遇到的是重复则计数累计，如果爆掉再继续i++而不填idx
				if (count >= 3)
				{
					continue;	//通过这个continue，让idx始终指向结果数组的最后一个位置
				}
			}
			else{
				//i == 0 || 出现新元素，则计数重置为1
				count = 1;
			}
			A[idx++] = A[i]; //A[idx] = A[i]; idx++; idx始终指向结果，挖坑填数，idx指向下一个要填的坑
			/*1.出现的新数会被填到结果数组；
			  2.出现的重复次数<= 2的数会被填到结果数组；
			  3.爆掉的数会被continue跳过而导致index指针和i错开，但index始终指向有效位置
			*/
		}
		return idx;
	}

	/*
	*	此方法只需要将所有的2改为3就可以用于允许重复三次的情况，前提是有序数组，当然这可以用排序实现
	*/
	int removeDuplicates_ii(int A[], int n){
		if (n <= 2)	//不超过2个的数组直接通过
		{
			return n;
		}
		int index = 2;	//从第3个元素开始，前两个元素通过，index指向第一个需要填的坑
		for (int i = 2; i < n; ++i)	//从第3个元素开始测试
		{
			if (A[i] != A[index - 2])	//归纳法，假设index之前的都是合法的
			{
				//如果A[i] == A[index-1]则有两个重复，如果A[i] == A[index-2]则说明有三个重复了，因为是有序数组，中间一定相等
				A[index++] = A[i]; //A[index] = A[i]; index++;
			}
		}

		return index; //index 指向的元素是个坑，但是 index = validElements + 1;正好不用+1
	}

};

int main(int argc, char const *argv[])
{
	int A[] = {1, 1, 1, 1, 2, 2, 2, 3};
	int n = sizeof(A)/sizeof(int);
	RemoveDuplicatesfromSortedArrayII rd;
	//int len = rd.removeDuplicates(A, n);
	int len = rd.removeDuplicates_ii(A, n);
	cout<< "len:\t" << len << endl;
	for (int i = 0; i < len; ++i)
	{
		cout<< A[i] << "\t";
	}

	return 0;
}
