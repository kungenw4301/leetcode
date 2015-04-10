class isValidBST
{
public:
    isValidBST();
    ~isValidBST();

    //struct TreeNode {
    //    int val;
    //    TreeNode *left;
    //    TreeNode *right;
    //    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    //}
    bool isValidBST(TreeNode *root){
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode *root, int lower, int upper){
        return lower < root->val && root->val < upper
                &&  isValidBST(root->left, lower, root->val)
                &&  isValidBST(root->right, root->val, upper);
    }

    //上述方法错误，最终不能通过所有测试用例
    //
    //

    TreeNode *pre = nullptr;

    //基于这样一个结论，二叉查找树的中序遍历是递增的
    //用一个 *pre 来记录刚刚遍历过的节点
    bool isValidBST(TreeNode *root){
    if (root != nullptr) {
            // Inorder traversal: left first.
            if (!isValidBST(root->left)) return false;

            // Compare it with the previous value in inorder traversal.
            if (pre != nullptr && root->val <= pre->val) return false;

            // Update the previous value.
            pre = root;

            // Inorder traversal: right last.
            return isValidBST(root->right);
            //便利顺序就是左中右
        }
        return true;

    }

};
