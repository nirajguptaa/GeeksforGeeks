// User function template for C++
struct Node{
    Node *links[26];
    bool flag=false;
    bool contains(char ch){
        return links[ch-'a']!=NULL;
    }
    bool setChar(char ch,Node *node){
        links[ch-'a']=node;
    }
    bool isEnd(){
        return flag;
    }
    
    void setEnd(){
        flag=true;
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
        
};
class Trie {
  public:
    Node *root;
    Trie() {
        // implement Trie
        root=new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                node->setChar(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string &word) {
        // search word in the Trie
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
    }
};
