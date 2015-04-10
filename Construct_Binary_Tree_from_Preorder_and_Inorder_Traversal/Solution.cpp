class Solution
{
public:
    Solution();
    ~Solution();
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }

    template<typename InputIterator>
    TreeNode * buildTree(InputIterator pre_first, InputIterator pre_last,
        InputIterator in_first, InputIterator in_last){
        if (pre_first == pre_last) return nullptr;
        if(in_first == in_last) return nullptr;

        auto root = new TreeNode(*pre_first); //此处应该是拷贝构造函数,不是拷贝，而是得到值
        auto inRootPos = find(in_first, in_last, *pre_first); //找到根节点的位置
        auto leftSize = distance(in_first, inRootPos); //返回的是InputIterator

        root->left = buildTree(next(pre_first), next(pre_first, leftSize + 1),
                                in_first, next(in_first, leftSize+1));
        //找出左子树的前序遍历、中序遍历，next(pre_first), next(pre_first, leftSize)就是前序，
        //leftSize+1是为了跳过整棵树的头节点,实际上是指向了左子树的最后一个节点的下一个位置
        //同理，in_first, next(in_fisrt, leftSize)就是左子树的中序遍历，最后指向最后节点下一位置
        root->right = buildTree(next(pre_first, leftSize+1), pre_last,
                                 next(inRootPos),in_last);

        return root;
    }
};
