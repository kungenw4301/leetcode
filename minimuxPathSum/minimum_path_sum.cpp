class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();

        int f[m][n]; //f[m][n]表示到(m, n)的路径和
        f[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i)
            f[i][0] = f[i-1][0] + grid[i][0];

        for(int i = 1; i < n; ++i)
            f[0][i] = f[0][i-1] + grid[0][i]; //计算行

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]; //左边或上边，取小的

        return f[m-1][n-1]; //到grid[m-1][n-1]为止的路径之和
    }
};
