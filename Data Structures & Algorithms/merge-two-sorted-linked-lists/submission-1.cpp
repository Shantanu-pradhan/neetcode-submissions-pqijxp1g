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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL;
        ListNode *node = NULL;
        while(list1 && list2){
            if(list1->val < list2->val){
                if(!head){
                    head = node = list1;
                } else {
                    node->next = list1;
                    node = node->next;
                }
                list1 = list1->next;
            } else {
                if(!head){
                    head = node = list2;
                } else {
                    node->next = list2;
                    node = node->next;
                }
                list2 = list2->next;
            }
        }
        if(list1){
            if(!head){
                    head = node = list1;
            } else {
                    node->next = list1;
            }
        }
        else if(list2){
            if(!head){
                    head = node = list2;
            } else {
                    node->next = list2;
            }
        }
        return head;
    }
};
