#include <iostream>
using namespace std;

class RotatedSortedArray
{
public:
	RotatedSortedArray();
	~RotatedSortedArray();
	int search(int A[], int n, int target){
		int first = 0, last = n;
		while(first != last){
			const int mid = (first + last) / 2;
			if (A[mid] == target)
			{
				return mid;
			}
			if (A[first] <= A[mid])
			{
				if (A[first] <= target && target <= A[mid])
				{
					last = mid;
				}
				else{
					first = mid + 1;
				}
			}else{
				if (A[mid] <= target && target <= A[last - 1])
				{
					first = mid;
				}else{
					last = mid;
				}
			}
		}
		return -1;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	int A[] = {4, 5, 6, 7, 0, 1, 2, 3};
	int target = 4;
	RotatedSortedArray rsa = new RotatedSortedArray;
	cout << rsa.search(A, 8, target) << endl;
	return 0;
}
