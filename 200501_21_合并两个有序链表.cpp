// 21. 合并两个有序链表
// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

// 示例：

// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

// https://leetcode-cn.com/problems/merge-two-sorted-lists/



//My Codes
// 执行结果：通过
// 执行用时 :8 ms, 在所有 C++ 提交中击败了80.33%的用户
// 内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //template
        ListNode*head=new ListNode(0);
        ListNode*p=head;
        ListNode* temp;
        
        while(l1||l2){
            if(!l1||((l1&&l2&&l1->val>=l2->val))){
                p->next=new ListNode(l2->val);
                p=p->next;
                temp=l2;
                l2=l2->next;
                delete temp;
            }
            else if(!l2||(l1&&l2&&l1->val<l2->val)){
                p->next=new ListNode(l1->val);
                p=p->next;
                temp=l1;
                l1=l1->next;
                delete temp;
            }
        }
        return head->next;
    }
};


//nice codes:

// # python四行

// # Definition for singly-linked list.
// # class ListNode:
// #     def __init__(self, x):
// #         self.val = x
// #         self.next = None

// class Solution:
//     def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
//         if l1 and l2:
//             if l1.val > l2.val: l1, l2 = l2, l1
//             l1.next = self.mergeTwoLists(l1.next, l2)
//         return l1 or l2

// 作者：QQqun902025048
// 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/python-4xing-by-knifezhu-3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。