// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int floor_val=-1;
        while(root){
            if(root->data==x){
                return x;
            }else if(root->data>x){
                
                root=root->left;
                
            }else{
                floor_val=root->data;
                root=root->right;
            }
        }
        return floor_val;
    }
};


//          50
//       /    \
//      30      70
//      / \    /  \
//   20  40  60  80