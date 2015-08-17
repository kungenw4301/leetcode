#include <iostream>
using namespace std;
class Solution{
public:
	//递归算法，向下f(m, n-1)，向下f(m-1, n)
	int uniquePaths(int m, int n){
		if(m < 1 || n < 1)
			return 0;	//m,n小于1肯定不合理
		if(m == 1 && n == 1)
			return 1;
		return uniquePaths(m, n-1) + uniquePaths(m-1, n); //向下和向右是不同的路径
	}

	int uniquePaths_ii(int m ,int n){
		int f[m][n];
		for(int i = 0; i < m; ++i)
			f[i][0] = 1;	//当列只剩下一个的时候只有一条路径

		for(int i = 0; i < n; ++i)
			f[0][i] = 1;	//当行只剩下一个的时候只有一条路径

		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j){
				f[i][j] = f[i - 1][j] + f[i][j-1];	//往下走 +　往右走
			}

		return f[m-1][n-1];
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	return 0;
}
