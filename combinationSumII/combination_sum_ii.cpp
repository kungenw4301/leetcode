class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> intermediate;
        vector<vector<int> > result;

        sort(candidates.begin(), candidates.end()); //排序，保证唯一，保证结果升序
        dfs(candidates, target, 0, intermediate, result);
        return result;
    }

    void dfs(vector<int> &nums, int gap, int start,
                 vector<int> &intermediate, vector<vector<int> > &result){
        if(gap == 0){
            result.push_back(intermediate);
            return;
        }

        //[1, 1] target = 1
        //没有prev记录: output: [[1], [1]], 因为上一轮的最后一个和本轮的第一个数重复了
        int prev = -1; //用于记录上次选了的最后一个数，去重
        for(size_t i = start; i < nums.size(); ++i){
            if(prev == nums[i]) continue;
            if(gap < nums[i])   return; //剪枝

            prev = nums[i]; //本轮的nums[i]没有超出gap，记录

            intermediate.push_back(nums[i]);
            dfs(nums, gap - nums[i], i + 1, intermediate, result);
            intermediate.pop_back();    //走到这步，证明向下递归都有了结果，故回溯，++i,继续
        }
    }
};
