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

    //递归版本
    vector<vector<int> > levelOrder_0(TreeNode *root) {
        vector<vector<int>> result;
        tranverse(root, 1, result);
        return result;
    }

    void tranverse(TreeNode *root, size_t level, vector<vector<int>> &result){
        if(!root) return;   //传入的节点为nullptr，则返回上一层递归，继续

        //运行到此处，只有两种可能：
        //1.level > result.size()  进入下一层，result加一层
        //2.level == result.size()  同一层，继续push_back()
        if(level > result.size())       //应当遍历level层，给result加一层
            result.push_back(vector<int>());    //实际运行时，左孩子进入时加一层，右孩子不用

        result[level - 1].push_back(root->val); //result从0开始，故level-1才是当前层记录
        tranverse(root->left, level + 1, result);
        tranverse(root->right, level + 1, result);
    }

    //非递归解法，使用两个queue，一个记录当前层，一个记录下一层
    vector<vector<int> > levelOrder_1(TreeNode *root){
        vector<vector<int> > result;
        if(!root) return result;    //会传入空树
        queue<TreeNode *> q1, q2;   //q1当前层，q2下一层
        q1.push(root);

        while(!q1.empty()){
            vector<int> level;  //记录当前层
            while(! q1.empty()){
                auto node = q1.front(); q1.pop();   //依次取出一个元素
                level.push_back(node->val);
                if(node->left) q2.push(node->left);
                if(node->right) q2.push(node->right);
            }

            std::swap(q1, q2);  //下一层变成当前层，准备下一次遍历；当前层则为空了，不必清理
            result.push_back(level);    //每次声明一个level，放入结果
        }

        return move(result);        //C++11的move语义，简单来说，即使result内容move给函数返回值的
                                    //接受者
                                    //但是result这个引用还在，但是变成未初始化了，节约内存
    }

    vector<vector<int> > levelOrder_2(TreeNode *root){
        vector<vector<int> > result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode * split = nullptr;
        while(!q.empty()){
            q.push(split);      //每次进入下一层的时候加一个隔板
            vector<int> level;

            while(q.front() != split){
                auto node = q.front();  q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            result.push_back(level);    //每一层结束，收集level
            q.pop();    //弹出当前层的split，进入下一层第一步就是在q末尾加隔板
        }

        return move(result);
    }
};
