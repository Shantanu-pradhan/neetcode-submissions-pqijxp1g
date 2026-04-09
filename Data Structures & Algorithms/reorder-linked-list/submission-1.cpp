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
        ListNode *node[10000];
        if(!head || !(head->next)){
            return;
        }
        ListNode *curr = head;
        int i=0, j=0, count = 0;
        while(curr){
            node[i++] = curr;
            curr = curr->next;
            count++;
        }
        i = 0;
        j = count-1;
        while(i < j){
            node[i++]->next = node[j];
            if(i>=j)
                break;
            node[j--]->next = node[i];
        }
        node[i]->next = NULL; 
    }
};
