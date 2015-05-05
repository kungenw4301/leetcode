class Solution {
public:
    //递归向下，回溯递归的典型题目
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> intermediate;
        dfs(candidates, target, 0, intermediate, result);
        return result;
    }

    void dfs(vector<int> &nums, int gap, int start,
             vector<int>& intermediate, vector<vector<int> > &result){
        if(gap == 0){   //递归出口，找到一个合法解
            result.push_back(intermediate);
            return;
        }

        for(size_t i = start; i < nums.size(); ++i){    //从start开始，递归向下
            if(gap < nums[i]) return;   //剪枝

            intermediate.push_back(nums[i]);    //扩展动作
            dfs(nums, gap - nums[i], i, intermediate, result);  //向下递归
            intermediate.pop_back();    //回溯
        }
    }
};
