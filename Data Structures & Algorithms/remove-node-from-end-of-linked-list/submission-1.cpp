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
        if(!head){
            return NULL;
        }
        ListNode *dummy_node = (ListNode *)malloc(sizeof(ListNode));
        if(!dummy_node){
            return NULL;
        }
        dummy_node->next = head;
        ListNode *tmp = head;
        for(int i=0; i<n; i++){
            tmp = tmp->next;
        }
        ListNode *tmp2 = dummy_node;
        while(tmp){
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
        tmp = tmp2->next;
        tmp2->next = tmp2->next->next;
        if(tmp == head){
            head = head->next;
        }
        free(tmp);
        free(dummy_node);
        return head;
    }
};
