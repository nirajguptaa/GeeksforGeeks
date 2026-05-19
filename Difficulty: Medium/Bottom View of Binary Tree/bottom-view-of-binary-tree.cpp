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
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL)return ans;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            Node *node=temp.first;
            int dist=temp.second;
            q.pop();
            mp[dist]=node->data;
            if(node->left){
                q.push({node->left,dist-1});
            }
            if(node->right){
                q.push({node->right,dist+1});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};