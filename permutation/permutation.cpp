class Solution{
public:
    vector<vector<int>> permute(vector<int> num){
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        vector<int> path; //存储每一个有效的排列，中间结果

        dfs(num, path, result); //递归深度优先搜索
        return result;
    }

private:
    void dfs(vector<int> & num, vector<int>& path, vector<vector<int>>& result){
        if (path.size() == num.size())
        {
            result.push_back(path); //收敛条件，一个排列完成
            return;
        }

        //扩展状态
        for(auto i: num){
            auto pos = find(path.begin(), path.end(), i); //遍历vector用全局的find

            if(pos == path.end()){   //当前值i没有出现在path中
                path.push_back(i);  //加入path
                dfs(num, path, result); //继续寻找下一层
                path.pop_back();        //这一句是回溯递归的关键点，path={1,2,3},回溯到{1,3},在往上回溯到{2,1,3}
            }
        }
    }
};
