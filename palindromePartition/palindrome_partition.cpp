class Solution {
public:
    //回溯递归，DFS
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        DFS(s, path, result, 0);
        return result;
    }

    bool isPalindrome(const string &s, int start, int end){
        while(start < end && s[start] == s[end]){
            ++start;
            --end;
        }

        return start >= end;    //start > end,奇数回文；start == end, 偶数回文；否则非回文
    }

    //搜索s[start] 开头的partition方案
    void DFS(string &s, vector<string> &path, vector<vector<string>> &result, int start){
        if(start == s.size()){
            result.push_back(path); //找到一种partition方案
            return;         //递归出口
        }

        for(int i = start; i < s.size(); ++i){
            if (isPalindrome(s, start, i))
            {
                //从i位置切一刀
               path.push_back(s.substr(start, i - start + 1));  //从start开始到i共 i - start + 1个
               DFS(s, path, result, i + 1); //start+1,继续往下切
               path.pop_back(); //吐出一个，循环继续，i+1
               //此处再进入循环，使得上一刀切出来的更长，path没变，但是从start到i+1
            }
        }
    }

    //动态规划，建立二维数组来表示是否回文
    vector<vector<string> > partitionDP(string s){
        const int n = s.size(); //决定二维数组的大小
        bool p[n][n];   //p[i][j]标识s[i]到s[j]是不是回文串
        fill_n(&p[0][0], n * n, false); //从p[0][0]开始填充n^2个false

        //从i到j判断回文，故i:0~(n-1), j: i~(n-1)
        //p[i][j]回文当且仅当p[i+1][j-1]回文 && s[i+1] == s[j-1]
        //细分：
        //1. s[i] == s[j] && p[i+1][j-1] && i+1<j-1, abba
        //2. s[i] == s[j] && p[i+1][j-1] && i+1==j-1, 中间只有一个字母, aba
        //3. s[i] == s[j] && j - i == 1, 中间有0个字母，aa
        //4. s[i] == s[j] && j - i == 0, 中间有0个字母，a
        for(int i = n - 1; i >= 0; --i)
            for(int j = i; j < n; ++j)
                p[i][j] = s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]);

        vector<vector<string> > sub_palin[n];   //n个二维数组，sub_palin[i]标识从i起的回文分割解

        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(p[i][j]){
                    const string palindrome = s.substr(i, j - i + 1);
                    if(j+1 < n){    //j < n - 1, j未到达string最后一位
                        //p[i][j]回文，sub_palin[j+1]表示从j+1位到n-1位的回文分割解，
                        //（要求的是0~n-1）,从j+1~n-1的解集中取出每一个元素，一个vector对应
                        //j+1到n-1的回文分割
                        //对每个vector插入p[i][j]回文串，最终得到i~n-1回文分割的解集
                        for(auto v : sub_palin[j + 1]){
                            v.insert(v.begin(), palindrome);
                            sub_palin[i].push_back(v);  //从i起的
                        }
                    }else{  //j == n - 1,s[i]~s[j]是一个回文串，sub_palin[i]得到一个解
                        sub_palin[i].push_back(vector<string>{palindrome});
                    }
                }
            }
        }

        return sub_palin[0];

    }
};
