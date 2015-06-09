class Solution {
public:
// LeetCode, Longest Common Prefix
// 纵向扫描，从位置 0 开始，对每一个位置比较所有字符串，直到遇到一个不匹配
// 时间复杂度 O(n1+n2+...)
// @author 周倩 (http://weibo.com/zhouditty)
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        for(int i = 0; i < strs[0].size(); ++i)
            for(int j = 1; j < strs.size(); ++j) //只需要从第1个开始即可
                if(strs[j][i] != strs[0][i]) return strs[0].substr(0, i);

        return strs[0]; //执行到此步，说明扫描到最后
    }
};
