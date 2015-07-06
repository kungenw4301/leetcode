class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        int i = 0;
        int maxArea = 0;
        height.push_back(0);    //插入一个dummy，0，能够统一处理
        while(i < height.size()){
            if(s.empty() || height[s.top()] <= height[i])
                s.push(i++);    //只要当前元素大于栈顶，则入栈，确保递增序列,记录索引
            else{
                int h = s.top(); //出栈，最高的一个bar的索引,top()获得栈顶元素，pop()没有返回值
                s.pop();
                //为什么是这个表达式，参考：
                //http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
                //栈非空：s.top()取出至i为止的第二高的索引，i - top2 - 1就是top1的宽度
                //      如果栈还是非空，则取出第二高的做高度，s.top()取出第三高的索引，
                //      i - top3 - 1就是top2到i的宽度
                //栈空：说明刚刚弹出的是最矮的一个bar，既然是最矮，可以直接计算从0到i-1作为宽度
                maxArea = max(maxArea, height[h] * (s.empty() ? i : (i - s.top() - 1)));
            }
        }

    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
//由于加了dummy节点，所以不用特殊处理最后剩余，因为dummy小于任意节点，所以必然最后到这里是empty()
/**
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }
**/
        return maxArea;
    }
};
