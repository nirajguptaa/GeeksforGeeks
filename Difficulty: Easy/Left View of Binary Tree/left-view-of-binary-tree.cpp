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
    void f(Node *root,int level,vector<int>&ans){
        if(root==NULL)return;
        if(ans.size()==level)ans.push_back(root->data);
        f(root->left,level+1,ans);
        f(root->right,level+1,ans);
    }
    vector<int> leftView(Node *root) {
        // code here
        if(root==NULL)return {};
        vector<int>ans;
        f(root,0,ans);
        return ans;
    }
};