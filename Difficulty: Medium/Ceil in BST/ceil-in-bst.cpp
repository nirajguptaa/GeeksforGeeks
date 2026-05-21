/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void findCeil(Node *root,int k,int &CeilVal){
       if(root==NULL)return ;
        if(root->data>=k ){
            CeilVal=min(CeilVal,root->data);
            findCeil(root->left,k,CeilVal);
        }else{
            
            findCeil(root->right,k,CeilVal);
        }
        
        
    }
    int findCeil(Node* root, int x) {
        // code here
        int CeilVal=INT_MAX;
        findCeil(root,x,CeilVal);
        return CeilVal==INT_MAX?-1:CeilVal;
    }
};
