class Solution {
public:
    //如果每次，从 i 往右扫描，每找到一个回文就算一次 DP 的话，就可以
    //转换为 f(i)= 区间 [i, n-1] 之间最小的 cut 数，n 为字符串长度，则状态转移方程为
    //f(i) = min { f(j + 1) + 1 } , i <= j < n
    //简而言之，f[i]单独一个字母肯定回文，后面[i+1]~[n-1]找最小分割
    int minCut(string s) {
        const int n = s.size();
        int f[n + 1];   //存储每个位置对应的最小分割, f[i] = (i, n - 1)最小回文分割
        bool p[n][n];
        fill_n(&p[0][0], n * n, false);

        //最坏情形，一个字母一个切分
        for(int i = 0; i <= n; ++i)
            f[i] = n - 1 - i;   //f[0] = n-1; f[n]=-1;

        for(int i = n - 1; i >= 0; --i)
            for(int j = i; j < n; ++j)  //(i, i)~(i, n-1)
                //p[i][j] == true
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
                {
                   p[i][j] = true;
                   f[i] = min(f[i], f[j + 1] + 1);  //p[i][j]回文，f[i] = (i,j) + f[j + 1],改进
                }

        return f[0];
    }
};
