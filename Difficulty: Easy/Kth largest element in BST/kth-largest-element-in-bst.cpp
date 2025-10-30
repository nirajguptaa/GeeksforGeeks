/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int rev_in(Node *root,int &k){
        if(root==NULL)return -1;
        int right=rev_in(root->right,k);
        if(right!=-1){
            return right;
        }
        k--;
        if(k==0)return root->data;
        return rev_in(root->left,k);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        return rev_in(root,k);
    }
};