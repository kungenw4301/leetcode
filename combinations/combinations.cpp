class Solution{
public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> result; //结果集
        vector<int> path;
        dfs(n, k, 1, 0, path, result);
        return result;
    }

    //start,标记从哪一个数开始取；cur，标记当前组合中已经有几个数了
    void dfs(int n, int k, int start, int cur, vector<int> &path, vector<vector<int>>& result){
        if (cur == k)   //递归退出条件，cur为当前path的长度
        {
            result.push_back(path); //长度达到要求，求得一个组合
        }
        for(int i = start; i <= n; ++i){
            path.push_back(i);  //path从start这个计数开始取指
            dfs(n, k, i + 1, cur + 1, path, result);
            path.pop_back();    //回溯递归关键一句，比如4取2，(1,2)->(1,3)
        }
    }
};
