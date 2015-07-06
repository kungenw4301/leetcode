class Solution{
public:
    int maximalRectangle(vector<vector<char> >& matrix){
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int> > ones(m, vector<int>(n, 0)); //初始化，一行一行处理
        int result = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                if(i == 0) ones[0][j] = matrix[i][j] == '1' ? 1 : 0; //第一行
                else
                    ones[i][j] = matrix[i][j] == '1' ? ones[i - 1][j] + 1 : 0; //累计上一行对应为止

            ones[i].push_back(-1); //加一个dummy节点，这样0到i层形成的矩形就能够统一形式进行运算
            result = max(result, largestRectangle(ones[i])); //一行一行处理，前面的行组成直方图
        }

        return result;
    }

    //详解见：http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
    //或者largest_rectangle_in_histogram那道题
    int largestRectangle(const vector<int>& height){
        stack<int> s;
        int i = 0;
        int maxArea = 0;
        //传进来的height已经加过 -1 这个dummy节点了
        while(i < height.size()){
            if(s.empty() || height[s.top()] <= height[i]) //保证递增序列
                s.push(i++);
            else{
                int h = s.top(); s.pop();
                maxArea = max(maxArea, height[h] * (s.empty() ? i : (i - s.top() - 1)));
            }
        }
        return maxArea;
    }
};
