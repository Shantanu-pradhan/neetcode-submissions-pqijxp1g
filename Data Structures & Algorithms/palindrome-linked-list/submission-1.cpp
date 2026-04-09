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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = prev;
        while((ptr2 != nullptr) && (ptr1->val == ptr2->val)){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr2 == nullptr){
            return true;
        }
        return false;
    }
};