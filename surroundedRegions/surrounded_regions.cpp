class Solution {
public:
    void solve(vector<vector<char>> &board) {
       int m = board.size();
       if(m == 0) return;
       int n = board[0].size();

       for(int col = 0; col < n; ++col){
        bfs(board, 0, col);
        bfs(board, m - 1, col);
       }

       for(int row = 0; row < m; ++row){
        bfs(board, row, 0);
        bfs(board, row, n - 1);
       }

       for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j){
            if(board[i][j] == '.')
                board[i][j] = 'O';  //如果是能从边界搜索到的o则通过标记来保留
            else if(board[i][j] == 'O')
                board[i][j] = 'X';  //非边界可达的o则替换掉
        }
    }

    bool check(int row, int col, vector<vector<char> > &board){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        if(board[row][col] == 'O')  //找到需要替换的地方
            return true;
        return false;
    }

    void bfs(vector<vector<char> > &board, int row, int col){
        queue<std::pair<int, int>> coords;  //坐标对列，元素师pair表示的坐标
        coords.push(std::pair<int, int>(row, col));  //广度优先，从传入的点开始

        while(!coords.empty()){
            int r = coords.front().first;
            int c = coords.front().second;
            coords.pop();

            if(check(r, c, board)){
                board[r][c] = '.';  //标记
                if(check(r - 1, c, board)) //上下左右，找到就加入队列，等待标记
                    coords.push(std::pair<int, int>(r - 1, c));
                if(check(r + 1, c, board))
                    coords.push(std::pair<int, int>(r + 1, c));
                if(check(r, c - 1, board))
                    coords.push(std::pair<int, int>(r, c - 1));
                if(check(r, c + 1, board))
                    coords.push(std::pair<int, int>(r, c + 1));
            }
        }
    }
};
