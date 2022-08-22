//https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        int n = count(head);
        stack<int>s;
        int i = 0;
        while(head){
        if(n%2 != 0){
            while(head){
            if(i<= int(n/2)-1){
                s.push(head->val);
            }
            else if(i== int(n/2)){
                head=head->next;
                i++;
                continue;
            }
                
            else{
               int u = s.top();
                s.pop();
                if(u != head->val)
                    return false;
            }
                head=head->next;
                i++;
          }
        }
        else{
            if(i<= (n/2)-1){
                s.push(head->val);
            }
            else{
                int u = s.top();
                s.pop();
                if(u!= head->val)
                    return false;
            }
            head=head->next;
            i++;
        }
        }
        return true;
    }
};