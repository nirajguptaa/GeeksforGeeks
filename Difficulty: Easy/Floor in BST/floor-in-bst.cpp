/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void findfloor(Node *root,int k,int &floorVal){
       if(root==NULL)return ;
        if(root->data<=k){
            floorVal=max(floorVal,root->data);
            findfloor(root->right,k,floorVal);
        }else{
            
            findfloor(root->left,k,floorVal);
        }
        
        
    }
    int findMaxFork(Node* root, int k) {
        // code here
        int floorVal=-1;
        findfloor(root,k,floorVal);
        return floorVal;
    }   
};