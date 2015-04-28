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
};
