#include <iostream>
using namespace std;

class RemoveDuplicatesfromSortedArray
{
public:
	int removeDuplicates(int A[], int n){
		if(n == 0) return 0; //边界条件判断，否则会出错
		int index = 0;

		for (int i = 1; i < n; ++i)
		{
			if (A[index] != A[i])
			{
				//相等的时候index不移动，找到下一个不等的元素了，将它复制过来填在当前index之后
				A[++index] = A[i];
			}
		}
		return index + 1; //length = index + 1;

		//使用 STL，一行解决，速度更快
		/*
			unique 去处重复，
			distance 获得两个迭代器之间的距离，元素个数
		*/
		return distance(A, unique(A, A + n));
	}

};

int main(int argc, char const *argv[])
{
	//C++中new返回的是相应的指针类型
	RemoveDuplicatesfromSortedArray *rd = new RemoveDuplicatesfromSortedArray;

	int A[]	= {1, 1, 1, 2};
	int n = sizeof(A)/sizeof(int);
	int length = rd->removeDuplicates(A, n);
	cout << "length: "<< length << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << A[i] << "\t";
	}
	return 0;
}
