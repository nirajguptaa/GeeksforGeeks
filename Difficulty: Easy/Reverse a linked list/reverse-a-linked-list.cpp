/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* node) {
        // code here
        if(node==NULL || node->next==NULL){
            return node;
        }
        Node *prev=NULL;
        Node *curr=node;
        while(curr){
            Node *ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
};