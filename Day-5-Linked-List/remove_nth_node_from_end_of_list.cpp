//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    int count(ListNode* temp){
        int c=0;
        while(temp){
            c++;
            temp=temp->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        if(!head->next)
            return NULL;
        int c = count(head);
        int pos = (c-n)+1;
        ListNode *prev,*curr=head;
        if(pos==1){
           head=head->next;
            return head;
        }
        while(curr){
            pos--;
            if(pos==0){
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr=curr->next;
        }
        return head;
    }
};