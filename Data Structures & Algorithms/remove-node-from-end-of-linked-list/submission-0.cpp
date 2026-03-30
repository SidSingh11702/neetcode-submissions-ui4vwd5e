/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* iter = head; int sz = 0;
        while (iter) sz++, iter = iter->next;
        if (sz == n) return head->next;
        iter = head;
        for (int i=0; i<sz-n-1; i++) iter = iter->next;
        iter->next = iter->next->next;
        return head;
    }
};
