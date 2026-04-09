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
        ListNode *tmp = head;
        if(!tmp){
            return NULL;
        }
        int count = 0;
        int i = 0;
        while(tmp){
            tmp = tmp->next;
            count++;
        }
        //if the first node from begenning gets deleted 
        int pos = count-n;
        if(!pos){
            head = head->next;
            free(tmp);
            return head;
        }
        //if first node form the end gets deletedd 
        tmp = head;
        for(int i=0; i<pos-1; i++){
            tmp = tmp->next;
        }
        ListNode *prev = tmp;
        tmp = tmp->next;
        prev->next = tmp->next;
        free(tmp);
        return head;
    }
};
