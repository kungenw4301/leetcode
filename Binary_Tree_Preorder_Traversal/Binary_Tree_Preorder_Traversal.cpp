#include <iostream>
class Binary_Tree_Preorder_Traversal
{
public:
	Binary_Tree_Preorder_Traversal();
	~Binary_Tree_Preorder_Traversal();
	vector<int> preorderTraversal(TreeNode *root){
		vector<int> result;
		const TreeNode *p = root;
		stack<const TreeNode *> s;

		if (p != nullptr)
		{
			s.push(p);
		}

		while(!s.empty()){
			p = s.top();
			s.pop();
			result.push_back(p->val);  //先访问当前节点，也就是root

			if (p->right != nullptr)
			{
				s.push(p->right);  //右子节点存储
			}
			if (p->left != nullptr)
			{
				s.push(p->left);   //左子节点存储
			}

			/**
			 * 这可以理解就是一个逆序的过程，因为root->left->right的访问顺序限制，所以需要
			 * 记录左右
			 * 存右->存左->出左->存左右->存左左->出左左->存左左右->存左左左
			 * 如此往复，对每个节点都先访问，然后存右再存左，再出左，在对这个左，同样进行下去
			 */
		}
		return result;
	}
};
