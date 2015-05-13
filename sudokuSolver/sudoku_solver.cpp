class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.'){
                    for(int k = 0; k < 9; ++k){
                        board[i][j] = '1' + k;  //字符换成数字，1~9逐个尝试
                        if(isValid(board, i, j) && solve(board))
                            return true;    //如果合法，递归向下，直到全部为真，退出
                        board[i][j] = '.';  //如果不合法，运行到此，回溯，向下
                    }

                    return false;
                }
            }

        return true;
    }

    //判断(x, y) 是否合法
    bool isValid(const vector<vector<char> > &board, int x, int y){
        int i, j;
        for(i = 0; i < 9; ++i)  //检查行
            if(i != x && board[i][y] == board[x][y])
                return false;   //行中有位置重复这一值

        for(j = 0; j < 9; ++j)  //检查列
            if(j!= y && board[x][j] == board[x][y])
                return false;

        //检查一个小九宫格里面的数字内容
        for(i = (x / 3) * 3; i < (x / 3) * 3 + 3; ++i)  //比如4:3,4,5; 7:6,7,8
            for(j = (y / 3) * 3; j < (y / 3) * 3 + 3; ++j)  //列
                if((i != x || j != y) && board[i][j] == board[x][y])
                    return false;

        return true;
    }
};
