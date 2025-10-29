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
  Node *findPre(Node *root,int key){
      
      Node*pre=NULL;
      while(root!=NULL){
          if(root->data<key){
            pre=root;
            root=root->right;
        }else{
            root=root->left;
        }
      }
      return pre;
      
  }
  Node *findSucc(Node *root,int key){
      Node *succ=NULL;
      while(root!=NULL){
          if(root->data>key){
              succ=root;
              root=root->left;
          }else{
              root=root->right;
          }
      }
      return succ;
          
  }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans;
        Node *pre=findPre(root,key);
        Node *succ=findSucc(root,key);
        ans.push_back(pre);
        ans.push_back(succ);
        return ans;
        
    }
};