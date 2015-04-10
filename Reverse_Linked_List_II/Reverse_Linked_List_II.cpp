class Reverse_Linked_List_II
{
public:
	Reverse_Linked_List_II();
	~Reverse_Linked_List_II();

	/**
	 * [reverseBetween description]
	 * @param
	 * @param
	 * @param
	 * @return
	 */
    ListNode *reverseBetween(ListNode *head, int m, int n){

/**
 * 1 ----->2----->3->4->5
 * ^       ^      ^
 * prevM  prev  curr
 *
 *
 *    |-------|
 *    |       v
 * 1->2   3-> 4->5
 *
 *    |--------|
 *    |        v
 * 1->2    3   4   5
 *    ^    |
 *    |----|
 *
 *    |---------|
 *    |         v
 * 1  2    3<-| 4   5
 * |  ^    |  |
 * |  |----|  |
 * |----------|
 *
 *
 * 1-->   3-->   2-->4-->5
 * ^             ^   ^
 * prevM        prev curr
 *
 *               --------|
 *               |       v
 * 1->    3--->  2-> 4-> 5
 *
 *               --------|
 *               |       v
 * 1->    3--->  2-> 4   5
 *        ^          |
 *        |----------|
 *
 *               ----------|
 *               |         v
 * 1      3--->  2   4 <-| 5
 * |      ^          |   |
 * |      |----------|   |
 * |---------------------|
 * ^
 * prevM
 *                    ^
 *               ^    |
 *              prev  |
 *                   curr
 *
 *
 *
 * 链表翻转和单链表两个节点反转是很类似的，代码很简单，但是不好理解
 * 着重记一下
 * prev 指向反转好的最后一个节点，其实一直不动，只是prev.next变
 * 注意prevM和prev都是一直指向同一个节点，但是如上图整理顺了，还是可以理解为prev会随着节点动
 * prevM指向反转好的节点的前一个节点，其实一直不动
 * curr指向当前待反转节点，每次反转后是curr走远了
 *
 * 形式上很统一
 * prev.next = curr.next;
 * curr.next = prevM.next;
 * prevM.next = curr
 */
    	ListNode dummy(-1);
    	dummy.next = head;
        //ListNode *prev = &dummy;
        ListNode *prevM = &dummy, *prev, *curr;
        for(int i=1; i<=n; i++){
        	if (i<m)  prevM = prevM->next;
        	else if(i==m) {
        		prev = prevM->next;
        		curr = prev->next;
        	}
        	else{
        		prev->next = curr->next;
        		curr->next = prevM->next;
        		prevM->next = curr; //头插法
        		curr = prev->next;
        	}
        }
        return dummy.next;  //注意一点，C++中指针引用成员函数必须用->,而对象使用则用点号
        /**
         * ListNode *dummy;
         * dummy->next;
         * (*dummy).next;
         *
         * ListNode dummy(-1);
         * dummy.next;
         */
    }
};
