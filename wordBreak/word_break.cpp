class Solution {
public:
    //f(i) = any_of(f(j)&&s[j + 1, i] belong-to dict), 0 <= j < i
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        //长度为n的字符串需要n+1个隔板
        vector<bool> f(s.size() + 1, false);
        f[0] = true; // 空字符串
        for(int i = 1; i <= s.size(); ++i)  //f[1] => s(0, 1 - 1)
            for(int j = i - 1; j >= 0; --j)
                //从0到i - 1，f[j] 是s(0, j - 1)是否可以分词，相当于插到s[i]前面的一个隔板
                if(f[j] && wordDict.find(s.substr(j ,i - j)) != wordDict.end()){
                    f[i] = true;
                    break;  //从0到i - 1逐个尝试是否有分词，找到则跳出，否则进行到最后还是false
                }

        return f[s.size()]; //s(0, s.size() - 1)正好对应f[s.size()];

    }
};
