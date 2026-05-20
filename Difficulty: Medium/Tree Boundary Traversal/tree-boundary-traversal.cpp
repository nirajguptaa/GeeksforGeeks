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
   bool isLeaf(Node *root){
       return (root->left==NULL && root->right==NULL);
   }
   void AddLeftBoundary(Node *root,vector<int>&ans){
       Node *curr=root->left;
       while(curr){
        if(!isLeaf(curr))ans.push_back(curr->data);
          if(curr->left){
              curr=curr->left;
          }else{
              curr=curr->right;
          }
              
       }
       
   }
   
   void AddLeaf(Node *root,vector<int>&ans){
       Node *curr=root;
       if(curr==NULL)return;
       if(isLeaf(curr)){
            ans.push_back(curr->data);
            return;
       }
       AddLeaf(root->left,ans);
       AddLeaf(root->right,ans);
   }
   void AddRightBoundary(Node *root,vector<int>&ans){
       Node *curr=root->right;
       vector<int>temp;
       while(curr){
            if(!isLeaf(curr))temp.push_back(curr->data);
           if(curr->right){
              curr=curr->right;
          }else {
              curr=curr->left;
          }
       }
       for(int i=temp.size()-1;i>=0;i--){
           ans.push_back(temp[i]);
       }
   }
   
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
            
        }
        AddLeftBoundary(root,ans);
        AddLeaf(root,ans);
        AddRightBoundary(root,ans);
        return ans;
    }
};