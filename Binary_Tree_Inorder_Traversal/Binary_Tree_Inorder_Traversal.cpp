#include <iostream>
class Binary_Tree_Inorder_Traversal
{
public:
	Binary_Tree_Inorder_Traversal();
	~Binary_Tree_Inorder_Traversal();
	vector<int> inorderTraversal(TreeNode *root){
		vector<int> result;
		const TreeNode *p = root; //用于指示当前遍历到的节点
		stack<const TreeNode *> s;  //非递归算法要借助栈结构

		while(!s.empty() || p != nullptr){ //辅助栈还有内容或者当前节点非空，继续
			if (p != nullptr)    //当前节点非空，记录访问足迹
			{
				s.push(p);    //记录访问足迹
				p = p->left;  //一直找更左的足迹
			}else{
				p = s.top();              //如果找到最左了，拿出栈顶
				result.push_back(p->val); //访问
				s.pop();  				  //访问过的去掉
				p = p->right;			  //处理完访问右边
				/**
				 * 你会疑问，比如 1
				 * 				  /\
				 * 				 2  3
				 * 				/    \
				 * 			   4      5
				 * 这种形式，访问最左后，处理4的右节点，还是空，但是此时p为空，还是继续出栈，访问
				 * 上一个做节点；
				 * 如果p != nullptr ，则针对4的右节点所在的一棵树，压栈，访问其左子节点
				 * 这么一想，就是相当于递归了（用循环的形式来达到递归）
				 * 不好理解，但是确实是对的
				 * 还可以看这棵树：1
				 * 				  / \
				 * 				 2   3
				 * 				/ \  / \
				 * 			   4   5 6  7
				 * 	有必要记下来，多看几遍，模拟几遍就理解了
				 */
			}
		}
		return result;
	}
};
