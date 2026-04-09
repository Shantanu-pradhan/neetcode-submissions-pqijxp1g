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
        ListNode *dummynode = new ListNode(0);
        ListNode *node = dummynode;
        ListNode *tmp1 = list1;
        ListNode *tmp2 = list2;
        while(tmp1 || tmp2){
            if(tmp1 && tmp2){
                if(tmp1->val < tmp2->val){
                    node->next = new ListNode(tmp1->val);
                    tmp1= tmp1->next;
                } else {
                    node->next = new ListNode(tmp2->val);
                    tmp2 = tmp2->next;
                }
            }
            else if(tmp1){
                node->next = new ListNode(tmp1->val);
                tmp1 = tmp1->next;
            }
            else if(tmp2){
                node->next = new ListNode(tmp2->val);
                tmp2 = tmp2->next;
            }
            node = node->next;
        }
        ListNode *res = dummynode->next;
        free(dummynode);
        return res;
    }
};
