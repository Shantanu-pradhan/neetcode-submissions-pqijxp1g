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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *tmp = NULL;
        int carry = 0;
        int sum=0;
        tmp = &dummy;
        int val1=0, val2=0;
        while(l1 || l2 || carry){
            val1=0;
            val2=0;
            if(l1){
                val1=l1->val;
                l1=l1->next;
            }
            if(l2){
                val2=l2->val;
                l2 = l2->next;
            }
            sum = (val1+val2+carry)%10;
            carry = (val1+val2+carry)/10;
            tmp->next = (ListNode *)malloc(sizeof(ListNode));
            tmp->next->val = sum;
            tmp = tmp->next;
        }
        tmp->next = NULL;
        return dummy.next;
    }
};
