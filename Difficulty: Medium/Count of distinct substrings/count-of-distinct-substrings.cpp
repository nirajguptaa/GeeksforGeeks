struct Node{
    unordered_map<char,Node *>links;
};
class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int count=0;
        Node *root=new Node();
        for(int i=0;i<s.size();i++){
            Node *node=root;
            for(int j=i;j<s.size();j++){
                char ch=s[j];
                if(node->links.find(ch)==node->links.end()){
                    node->links[ch]=new Node();
                    count++;
                }
                node=node->links[ch];
            }
        }
        return count;
    }
};