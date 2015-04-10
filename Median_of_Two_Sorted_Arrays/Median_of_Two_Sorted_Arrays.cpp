#include <iostream>
using namespace std;
class MedianofTwoSortedArrays
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n){
		int total = m + n;
		if (total & 0x1)
		{
			//如果是奇数，找中间这个
			return find_kth(A, m, B, n, total/2 + 1);
		}else{
			//如果是偶数吗，还是找中间位置，即中间两个数的平均
			return (find_kth(A, m, B, n, total/2)
					+find_kth(A, m, B, n, total/2+1))/2.0;    //这里一定要注意，/2.0才是取平均
			//返回double的意义就在于取平均，如 A;{}, B:{2,3}应当得到2.5，而不是2
		}
	}

private:
	static int find_kth(int A[], int m, int B[], int n, int k){
		if (m > n)
		{	//不妨假设m < n
			return find_kth(B, n, A, m, k);
		}
		if (m == 0)
		{
			return B[k-1];
		}
		if (k == 1)
		{
			return min(A[0], B[0]);
		}

		//二分查找，淘汰小的那部分
		//ia 是A中的划分尺度，ib是B中的划分尺度，保证ia+ib=k
		int ia = min(k/2, m), ib = k - ia;  //如果k/2大于m则取m
		if (A[ia - 1] < B[ib - 1])
		{
			return find_kth(A+ia, m-ia, B, n, k-ia);    //去掉A中前ia段
		}else if (A[ia-1]>B[ib-1])
		{
			return find_kth(A, m, B+ib, n-ib, k-ib);    //去掉B中前ib段
		}else{
			return A[ia-1];
		}
	}
};
