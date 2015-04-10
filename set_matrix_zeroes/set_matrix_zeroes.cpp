class set_matrix_zeroes
{
public:
    set_matrix_zeroes();
    ~set_matrix_zeroes();
    void setZeroes(vector<vector<int>> &matrix){
        const size_t m = matrix.size(); //获得矩阵宽度
        const size_t n = matrix[0].size(); //获得矩阵长度

        vector<bool> row(m, false); //标记每一行是否存在0
        vector<bool> col(n, false); //标记每一列是否存在0

        for(int i=0; i<m; i++)
            for (int j = 0; j < n; ++j)
                if(matrix[i][j] == 0) row[i] = col[j] = true;
            //存在0，标记该行该列为true

        for (int i = 0; i < m; ++i)
            if(row[i] == true) fill(&matrix[i][0], &matrix[i][0] + n, 0);
        //对于整个vector，给出头尾地址，填充0

        for(int j = 0; j < n; ++j)
            if (col[j] == true)
            {
                for (int i = 0; i < m; ++i)
                {
                    matrix[i][j] = 0;  //m[0][j],(1,j),(2,j),...,(m,j)
                }
            }

    }
};
