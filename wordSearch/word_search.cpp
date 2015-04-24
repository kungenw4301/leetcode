class Solution{
public:
    bool exist(vector<vector<char>> &board, string word){
        const int m = board.size(); //行数
        const int n = board[0].size(); //列数
        vector<vector<bool>> visited(m, vector<bool>(n, false)); //m*n个false填充vector，初始化记录

        for (int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(dfs(board, word, 0, i, j, visited))
                    return true;
        return false;   //全部搜索完毕，不符合条件
    }

private:
    bool dfs(const vector<vector<char>> &board, const string& word,
                 int index, int x, int y, vector<vector<bool>> &visited){
        if(index == word.size())
            return true;            //收敛条件

        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;       //越界，终止条件，x,y代表坐标

        if(visited[x][y])
            return false;       //已经访问过了，剪枝

        if(board[x][y] != word[index])
            return false;       //已经访问过了，剪枝

        visited[x][y] = true;   //符合条件，开始搜索

        bool ret =  dfs(board, word, index + 1, x - 1, y, visited) ||
                    dfs(board, word, index + 1, x + 1, y, visited) ||
                    dfs(board, word, index + 1, x , y - 1, visited) ||
                    dfs(board, word, index + 1, x , y + 1, visited); //上下左右
    }
};
