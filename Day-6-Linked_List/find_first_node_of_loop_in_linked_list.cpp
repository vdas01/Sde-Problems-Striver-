//https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
Node* detectLoop(Node* head){
   Node *fast=head,*slow = head;
   while(fast && slow && fast->next){
       fast = fast->next->next;
       slow = slow->next;
       if(fast == slow) break;
   }
   if(fast != slow) return NULL;
   slow = head;
   while(fast != slow){
       slow = slow->next;
       fast = fast->next;
   }
   return slow;
}