#include <iostream>
using namespace std;
class AddTwoNumbers
{
public:
	AddTwoNumbers();
	~AddTwoNumbers();
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		ListNode dummy(-1);
		int carry = 0;
		ListNode *prev = &dummy; //虚拟头结点
		for (ListNode *pa = l1, *pb = l2;  //初始化两个指针，因为题目给出reverse order，故不必反转
			pa != nullptr || pb != nullptr;  //只要还有一个链表有元素就继续加
			pa = pa == nullptr ? 0 : pa->next,     //优先级 ?: 高于 == 高于 =
			pb = pb == nullptr ? 0 : pb->next,
			prev = prev->next)   //每次移动一个位置，指向最后一个元素处，方便在尾部接上下一节点
		{
			const int ai = pa == nullptr ? 0 : pa->val;
			const int bi = pb == nullptr ? 0 : pb->val;
			const int value = (ai+bi+carry)%10;    //十进制，取模
			carry = (ai+bi+carry)/10;              //取商
			prev->next = new ListNode(value); //尾插法，prev每次指向当前最后一个节点
		}

		if (carry>0)
		{
			prev->next = new ListNode(carry);
		}

		return dummy.next; //返回虚拟头节点下一节点就是真实的数字
	}
};
