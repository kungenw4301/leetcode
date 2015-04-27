/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode *root, int sum){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr)   //递归出口
            return sum * 10 + root->val;    //叶节点，返回累计值

        //递归，分别左子树，右子树
        return dfs(root->left, sum * 10 + root->val)
                + dfs(root->right, sum * 10 + root->val);
    }
};
