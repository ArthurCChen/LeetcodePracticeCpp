// 25. K 个一组翻转链表
// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。

// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

// 示例：

// 给你这个链表：1->2->3->4->5

// 当 k = 2 时，应当返回: 2->1->4->3->5

// 当 k = 3 时，应当返回: 3->2->1->4->5

// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/



//My Codes
// 执行结果：通过
// 执行用时 :28 ms, 在所有 C++ 提交中击败了33.95%的用户
// 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) 
            {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};


//nice codes:

// powcai

// 递归写法

// class Solution:
//     def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

//         # 判断是否有k个节点
//         def cal_len(head):
//             p = head
//             l = 0
//             while p:
//                 l += 1
//                 p = p.next
//                 if l >= k: return True
//             return False

//         # 翻转k个节点
//         def reverseK(head, k):
//             prev, cur = None, head
//             while k:
//                 nxt = cur.next
//                 cur.next = prev
//                 prev = cur
//                 cur = nxt
//                 k -= 1
//             return prev, cur

//         # 递归
//         def dfs(head, k):
//             if not cal_len(head): return head
//             prev, cur = reverseK(head, k)
//             head.next = dfs(cur, k)
//             return prev
        
//         return dfs(head, k)