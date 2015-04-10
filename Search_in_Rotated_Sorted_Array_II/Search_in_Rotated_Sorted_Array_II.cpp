#include <iostream>
class Search_in_Rotated_Sorted_Array_II
{
public:
	/*
	*策略就是
	*1.通过比较A[first] 和 A[mid]确定前半段有序还是后半段
	*2.判断是不是在有序段，如果在则进入有序段；
	*3.不在有序段则在无序段，所以一个if分支既确定了有序段，又确定了查找范围
	*/
	bool search(int A[], int n, int target) {
     	int first = 0, last = n;
     	while(first != last){
     		const int mid = (first + last)/2;
     		if (A[mid] == target)
     		{
     			return true;
     		}
     		if (A[first] < A[mid]) //A[first] < A[mid] 肯定前一半有序
     		{
     			if (A[first] <= target && target <= A[mid]) //如果在有序段，则找有序段
     			{
     				last = mid;
     			}else{
     				first = mid + 1; //不在有序段，直接抛到无序段（旋转过）
     			}
     		}
     		else if (A[first] > A[mid]) //A[first] > A[mid] 说明肯定旋转过，前半段乱序
     		{
     			if (A[mid] <= target && target <= A[last - 1]) //后半段肯定有序，在有序段找
     			{
     				first = mid + 1;
     			}else{
     				last = mid;	//后半段有序，但不在有序段，找前半段
     			}
     		}else{
     			//
     			first++;	//A[first] = A[mid]，可能有序，可能无序,{1,1,1,3},{1,3,1,1,1}
     		}
     	}
     	return false;
    }
};

int main(int argc, char const *argv[])
{
	int A[] = {4, 4, 5, 5, 6, 6, 7, 8, 0, 1, 2, 3};
	int n = sizeof(A)/sizeof(A[0]);
	int target = 0;
	return 0;
}
