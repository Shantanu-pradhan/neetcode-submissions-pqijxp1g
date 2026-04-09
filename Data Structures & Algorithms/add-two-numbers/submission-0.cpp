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
        //if both l1 and l2 are NULL then return ?
        ListNode dummy;
        int carry = 0;
        int v1 = 0;
        int v2 = 0;
        int res = 0;
        ListNode *curr = &dummy;
        while(l1 || l2 || carry){
            v1 = 0;
            v2 = 0;
            if(l1){
                v1 = l1->val;
                l1 = l1->next;
            }
            if(l2){
                v2 = l2->val;
                l2 = l2->next;
            }
            res = (v1+v2+carry)%10;
            carry = (v1+v2+carry)/10;
            curr->next = (ListNode *)malloc(sizeof(ListNode));
            /*if(!(curr->next)){
                //Free all the nodes and return NULL
            }*/
            curr->next->val = res;
            curr = curr->next;
        }
        return dummy.next;
    }
};
