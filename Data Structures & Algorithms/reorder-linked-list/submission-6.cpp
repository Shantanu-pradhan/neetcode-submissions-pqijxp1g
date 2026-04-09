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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *fh = head;
        ListNode *sh = prev;
        while(sh){
            ListNode *tmp1 = fh->next;
            ListNode *tmp2 = sh->next;
            fh->next = sh;
            sh->next = tmp1;
            fh = tmp1;
            sh = tmp2;
        }
        fh->next = nullptr;
    }
};
