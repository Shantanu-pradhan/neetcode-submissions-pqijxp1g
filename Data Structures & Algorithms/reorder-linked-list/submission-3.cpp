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
        /*Find the middle of the linked list*/
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        /*Reverse the second half of the linkedlist*/
        ListNode *curr = slow->next;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *first_half = head;
        ListNode *second_half = prev;
        /*Merge the first half and the second half*/
        while(second_half){
            ListNode *tmp1 = first_half->next;
            ListNode *tmp2 = second_half->next;
            first_half->next = second_half;
            second_half->next = tmp1;
            second_half = tmp2;
            first_half = tmp1;
        }
        first_half->next = nullptr;
    }
};
