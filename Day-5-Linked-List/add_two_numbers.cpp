//https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result= new ListNode();
        ListNode *temp;
        result->val = 0;
        result->next = NULL;
        temp = result;
        int carry =0;
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+= l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=0;
            ListNode *nod = new ListNode();
            nod->val = (sum%10);
            nod->next = NULL;
            carry = (sum/10);
            temp->next = nod;
            temp = temp->next;
        }
        return result->next;
    }
};