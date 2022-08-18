//https://leetcode.com/problems/middle-of-the-linked-list/
class Solution {
public:
    int count(ListNode* temp){
        int c =0;
        while(temp!= NULL){
            c++;
            temp=temp->next;
        }
        return c;
    }
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        int n = count(head);
        if(n%2) n = (n/2)+1;
        else
             n=(n/2)+1;
        ListNode *temp=head;
        int c=0;
        while(temp!=NULL){
            if(c==n-1)
                return temp;
            c++;
            temp=temp->next;
        }
        return temp;
    }
};