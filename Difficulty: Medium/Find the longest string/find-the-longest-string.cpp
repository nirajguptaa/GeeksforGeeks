struct Node{
    Node *links[26];
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    bool flag=false;
    bool isEnd(){
        return flag;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
};
class Solution {
  public:
  Node *root;
  Solution(){
      
    root=new Node();
  }
    void insert(string word){
        Node *node=root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
        node->setEnd();
    }
    bool checkPrefix(string word){
        Node *node =root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(!node->isEnd()){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
        
    }
    string longestString(vector<string> &words) {
        // code here
        for(string word:words){
            insert(word);
        }
        string ans="";
        for(string word:words){
            if(checkPrefix(word)){
                if(word.size()>ans.size()){
                    ans=word;
                }else if(word.size()==ans.size() && word<ans){
                    ans=word;
                }
            }
        }
        return ans;
    }
};