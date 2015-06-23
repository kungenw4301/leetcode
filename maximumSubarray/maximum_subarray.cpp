class Solution {
public:
    //状态转移方程：f[j] = max { f[j - 1] + S[j], S[j] } , 其中1 <= j <= n
    //解释：
    //1.  情况一，S[j] 不独立，与前面的某些数组成一个连续子序列，则最大连续子序列和为
    //  f[j-1] + S[j]。
    //2.  情况二，S[j] 独立划分成为一段，即连续子序列仅包含一个数 S[j]，则最大连续子序列和为
    //  S[j]。
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, f = 0;
        for(int i = 0; i < nums.size(); ++i){
            f = max(f + nums[i], nums[i]); //对于f[j]，若f[j-1]<=0，则nums[j]重新开始累计
            result = max(result, f); //记录最大值
        }
        return result;
    }
};
