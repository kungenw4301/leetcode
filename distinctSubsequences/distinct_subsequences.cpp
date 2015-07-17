class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> f(t.size()+1); //多一个0长度的
        f[0] = 1;
        for(int i = 0; i < s.size(); ++i)
            //这里为什么要从后向前？
            //或许此处可以解释：http://bangbingsyb.blogspot.com/2014/11/leetcode-distinct-subsequences.html
            for(int j = t.size() - 1; j >= 0; --j)
                f[j+1] += (s[i] == t[j]) ? f[j] : 0;
        return f[t.size()];
    }
};
