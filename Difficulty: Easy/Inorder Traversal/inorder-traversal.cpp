/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>inorder;
        Node *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->data);
                curr=curr->right;
            }else{
                Node *prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=NULL;
                    inorder.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};