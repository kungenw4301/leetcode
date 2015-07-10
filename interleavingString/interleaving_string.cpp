#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave_recursion(string s1, string s2, string s3) {
        return isInterleave_recursion(s1, s1.length() - 1, s2, s2.length() - 1, s3, s3.length() - 1);
    }

    bool isInterleave_recursion(string s1, int i1, string s2, int i2, string s3, int i3){
        //这个条件不理解
        //这个条件是错的，亲测："aa", "b", "aba"
        if(i1 < 0 || i2 < 0 || i3 < 0) return i1 < 0 && i2 < 0 && i3 < 0;
        if(s1[i1] == s3[i3] && isInterleave_recursion(s1, i1 - 1, s2, i2, s3, i3 - 1))
            return true; //从s1串末尾划掉一个字母
        if(s2[i2] == s3[i3] && isInterleave_recursion(s1, i1, s2, i2 - 1, s3, i3 - 1))
            return true; //从s2串末尾划掉一个字母
        return false;
    }


    //dynamic programming
    //设状态 f[i][j]，表示 s1[0,i] 和 s2[0,j]，匹配 s3[0, i+j]。如果 s1 的最后一个字符等
    //于 s3 的最后一个字符，则 f[i][j]=f[i-1][j]；如果 s2 的最后一个字符等于 s3 的最后一个字符，
    //则 f[i][j]=f[i][j-1]。因此状态转移方程如下：
    //f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j])
    //              || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);
    bool isInterleave(string s1, string s2, string s3){
        if(s3.length() != s1.length() + s2.length())
            return false;

        int m = s1.length(), n = s2.length();
        vector<vector<bool> > f(m + 1,  vector<bool>(n+1, true)); //多出第0行，第0列

        for(int i = 1; i <= m; ++i)
            f[i][0] = f[i-1][0] && s1[i-1] == s3[i - 1]; //s2空，f[1][0]表示s1为0~0，s2为空

        for(int i = 1; i <= n; ++i)
            f[0][i] = f[0][i-1] && s2[i-1] == s3[i-1]; //s1空，比较s2和s3

        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j])
                            || (s2[j-1] == s3[i+j-1] && f[i][j-1]);

        return f[m][n]; //f[i][j]: s1[0:m-1] s2[0:n-1] s3[0:m+n-1]
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "aa";
    string s2 = "b";
    string s3 = "aba";
    Solution so;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << so.isInterleave(s1, s2, s3) << endl;
    return 0;
}
