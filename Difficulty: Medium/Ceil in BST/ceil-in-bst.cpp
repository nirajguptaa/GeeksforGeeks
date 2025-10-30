class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil_val=-1;
        while(root!=NULL){
            if(root->data==x){
                return x;
            }else if(root->data>x){
                ceil_val=root->data;
                root=root->left;
            }else{
                root=root->right;
            }
        }
        return ceil_val;
    }
};
