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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(val+1, head);
        ListNode *list = dummy;
        while(list && list->next){
            if(list->next->val == val){
                ListNode *tmp = list->next;
                list->next = tmp->next;
                delete tmp;
            }else {
                list = list->next;
            }
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;

    }
};