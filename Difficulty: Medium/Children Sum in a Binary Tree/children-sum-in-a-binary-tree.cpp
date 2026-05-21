/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isBal(Node *root){
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)return true;
        int leftData=root->left==NULL?0:root->left->data;
        int rightData=root->right==NULL?0:root->right->data;
        if(leftData+rightData!=root->data){
            return false;
            
        }
        return isBal(root->left) && isBal(root->right);
    }
    bool isSumProperty(Node *root) {
        // code here
        
        return isBal(root);
    }
};