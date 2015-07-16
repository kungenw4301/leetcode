class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        int f[m+1][n+1]; //f[m][n]对应word1[0:m], word2[0:n]
        for(int i = 0; i <= m; ++i)
            f[i][0] = i; //word2长度为0时，只能添加

        for(int i = 0; i <= n; ++i)
            f[0][i] = i;

        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j){
                if(word1[i-1] == word2[j-1]) //最后一个字符相同
                    f[i][j] = f[i-1][j-1]; //规模缩小
                else{
                    //f[i-1][j]是假设删掉word1最后一个相同，
                    //f[i][j-1]则是假设在word1后面加上一个字母相同
                    int mn = min(f[i-1][j], f[i][j-1]);
                    //如果是替换最后一个字母就相同，则是f[i-1][j-1] + 1
                    f[i][j] = min(f[i-1][j-1], mn) + 1;
                }
            }

        return f[m][n];
    }
};
