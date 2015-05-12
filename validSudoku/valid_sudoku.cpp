class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];

        for(int i = 0; i < 9; ++i){
            fill(used, used + 9, false);

            for(int j = 0; j < 9; ++j){
                if(!check(board[i][j], used))
                    return false;   //检查列，有任何一个无效则整个无效
            }

            fill(used, used + 9, false);    //每次新的检查要重置

            for(int j = 0; j < 9; ++j){
                if(!check(board[j][i], used))
                    return false;   //检查行，有任何一个无效则整个无效
            }
        }

        for(int r = 0; r < 3; ++r)
            for(int c = 0; c < 3; ++c){
                fill(used, used + 9, false);

                for(int i = r * 3; i < r * 3 + 3; ++i) //例如r=1,c=1，则是第3/4/5行，3/4/5列
                    for(int j = c * 3; j < c * 3 + 3; ++j){
                        if(!check(board[i][j], used))
                            return false;
                    }
            }  //第r行，第c列个九宫格

        return true;
    }

    bool check(char ch, bool used[9]){
        if(ch == '.')   return true;    //这个格子是空，有效

        if(used[ch - '1'])  return false;   //这个格子里的数被该行、列、九宫格使用过，无效

        return used[ch - '1'] = true;   //相当于 used[ch - '1'] = true; return 1;
    }
};
