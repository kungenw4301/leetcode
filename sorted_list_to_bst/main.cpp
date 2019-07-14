/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//109. Convert Sorted List to Binary Search Tree
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 找到中心节点，作为 root，左右子列表递归处理
        // 递归出口是 left / right 为空
        if (head == nullptr)
        {
        	return nullptr;
        }

        if (head->next == nullptr)
        {
        	return new TreeNode(head->val);
        }
        ListNode* mid = findMid(head);

        TreeNode* root = new TreeNode(mid->val);

        root->left = sortedListToBST(head); //已经做了截断
        
        root->right = sortedListToBST(mid->next); // (mid, tail]

        return root;
    }

    //使用快慢指针，快的走两步，慢的一步，快的到头，慢的找到中部
    /**  eg:  1 -> 2 -> 3
    		 |    |    |
    		 cut  slow  fast
    **/
    ListNode* findMid(ListNode* head) {
    	if (head == nullptr)
    	{
    		return nullptr;
    	}

    	ListNode* fast = head;
    	ListNode* slow = head;
    	ListNode* cut = head; //找到中点就断开，拆分成 [head, mid) mid [mid->next, tail]

    	while(fast != nullptr && fast->next != nullptr) {	//停在 tail 前一个节点
    		cut = slow;
    		slow = slow->next;
    		fast = fast->next->next;
    	}

    	cut->next = nullptr; //截断中部前
    	return slow;
    }
};