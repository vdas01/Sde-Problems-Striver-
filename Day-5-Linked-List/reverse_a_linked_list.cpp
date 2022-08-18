//https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode *prev = NULL,*pres = head,*nex = head->next;
        while(pres != 0){
            pres->next = prev;
            prev = pres;
            pres = nex;
            if(nex!=0)
            nex = nex->next;
        }
        return prev;
    }
};