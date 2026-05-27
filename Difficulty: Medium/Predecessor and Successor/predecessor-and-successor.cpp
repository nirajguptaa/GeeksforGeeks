/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node *pre=NULL;
        Node *succ=NULL;
        
        while(root){
            if(root->data==key){
                if(root->left){
                    Node *curr=root->left;
                    while(curr->right){
                        curr=curr->right;
                    }
                    pre=curr;
                }
                if(root->right){
                    Node *curr=root->right;
                    while(curr->left){
                        curr=curr->left;
                    }
                    succ=curr;
                }
                break;
            }
            else if(root->data<key){
                pre=root;
                root=root->right;
            }else{
                succ=root;
                root=root->left;
            }
        }
        return {pre,succ};
    }
};