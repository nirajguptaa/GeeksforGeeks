/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head) {
       
        if(head==NULL)return NULL;
        Node *prev=NULL;
        Node *curr=head;
        while(curr){
            Node *ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // code here
        head=reverse(head);
        Node *curr=head;
        int maxi=curr->data;
        while(curr && curr->next){
            if(curr->next->data<maxi){
                Node *temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }else{
                curr=curr->next;
                maxi=max(maxi,curr->data);
            }
        }
        return reverse(head);
    }
};