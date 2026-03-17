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
    void f(Node *root,int lev,vector<int>&ans){
        if(ans.size()==lev){
            ans.push_back(root->data);
        }
        if(root->left){
            f(root->left,lev+1,ans);
        }
        if(root->right){
            f(root->right,lev+1,ans);
        }
            
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        f(root,0,ans);
        return ans;
    }
};