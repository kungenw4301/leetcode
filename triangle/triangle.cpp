class Solution {
public:
    //状态转移方程：f(i, j) = min { f(i, j + 1), f(i + 1, j + 1) } + (i, j)
    //空间复杂度为O(1)的前提是triangle可以改变
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i = triangle.size()-2; i >= 0; --i) //下往上，注意结束序号
            for(int j = 0; j <= i; ++j)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);

        return triangle[0][0];
    }
};
