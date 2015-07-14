class Solution {
public:
    bool isScramble_recr(string s1, string s2) {
        if(s1.length() != s2.length()) return false; //长度不等，淘汰
        if(s1 == s2) return true; //相等也是一种scramble，考虑完全只有左叶子的二叉树和右叶子的
        if(!isSameChar(s1, s2)) return false; //每个字母频率是否相等
        int n = s1.length();
        for(int i = 1; i < n; ++i){ //i在这里是长度, 第一个串的划分可以是长度为1，2，3，...，n-1
            if(isScramble(s1.substr(0, i), s2.substr(0, i))
                && isScramble(s1.substr(i, n-i), s2.substr(i, n-i)))
                return true; //向下递归，[0:i-1] [i, n-1]
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i))
                && isScramble(s1.substr(i, n-i), s2.substr(0, n-i)))
                //s1[0:i-1] s2[n-i:n-1]，镜像位置对称
                return true; //向下递归，[0:i-1] [i, n-1]
        }
        return false; //如果都没有满足，最后就是false
    }

    bool isSameChar(string s1, string s2){
        int x[26] = {0}; //一个数组，记录25个字母出现的频率
        for(int i = 0; i < s1.length(); ++i)
            ++x[s1[i] - 'a']; //例如s1[1] == 'b' ，则x[1]++，累加对应字母出现次数
        for(int i = 0; i < s2.length(); ++i)
            --x[s2[i] - 'a']; //s2串中每个对应字母减去频率，对称逆运算
        for(int i = 0; i < 26; ++i)
            if(x[i] != 0) return false;
        return true; //统计的是每个字母出现的频率是否相同
    }

    bool isScramble(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        int n = s1.length();
        //n+1 * n * n
        //dp[n][i][j] s1[i:i+n-1] s2[j:j+n-1]

        //这个动态创建三层vector，异常耗时，AC花了128ms
        //换成数组就正常了
        //vector<vector<vector<bool> > > dp(n+1, vector<vector<bool> >(n, vector<bool>(n, false)));

        bool dp[n+1][n][n] = {false};

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                dp[1][i][j] = s1[i] == s2[j]; //长度为1

        for(int len = 2; len <= n; ++len) //每次取的串的总长度
            for(int i = 0; i <= n-len; ++i) //为什么是n-len，保证从i取(不如n-len)一定能取到len个
                for(int j = 0; j <= n-len; ++j)
                    for(int k = 1; k < len; ++k) //k是第一个串划分的长度,k==1就是 s1[0:0] s1[1:n]
                        if((dp[k][i][j] && dp[len-k][i+k][j+k])
                         ||(dp[k][i][j+len-k] && dp[len-k][i+k][j]) ){
                            //[i:i+k-1] [i+k:i+len-1] 长len
                            //第二行对称取，为何是j+len-k?
                        //[i:i+k-1]供k个，s2从j开始，j+len-1结束，倒着取j+len-1, j+len-2到j+len-k
                            dp[len][i][j] = true; //四个字符串,两种划分，镜像或者顺序，为真即可
                            break; //找到一种划分即可，比如 k==1 时成立就代表长len的串scramble
                        }

        return dp[n][0][0]; //长度为0的不考虑，初始化时全置为false
    }
};
