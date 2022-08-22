//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* end(Node* temp){
        while(temp->next)
        temp=temp->next;
        return temp;
    }
    Node* rotate(Node* head, int k)
    {
        if(!head)
        return NULL;
        if(!head->next)
        return head;
        Node *tail = end(head);
        while(k){
            k--;
            tail->next = head;
            tail = head;
            head= head->next;
             tail->next = NULL;
        }
        return head;
    }
};