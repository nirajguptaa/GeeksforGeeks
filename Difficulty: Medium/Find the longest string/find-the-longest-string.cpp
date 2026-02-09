struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool isEnd(){
        return flag;
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
  void insert(string &word){
      Node *node=root;
      for(int i=0;i<word.size();i++){
          if(!node->containsKey(word[i])){
              node->put(word[i],new Node());
          }
          node=node->get(word[i]);
      }
      node->setEnd();
  }
  bool checkPrefix(string word){
      Node *node=root;
      for(int i=0;i<word.size()-1;i++){
          if(node->containsKey(word[i])){
              node=node->get(word[i]);
          }
          if(node->isEnd()==false){
              return false;
          }
      }
      return true;
  }
    string longestString(vector<string> &words) {
        // code here
        if(words.empty())return "";
        for(auto word:words){
            if(word.empty()){
                return "";
            }
            insert(word);
        }
        string longest="";
        for(string word:words){
            if(checkPrefix(word)){
                if(word.length()>longest.length()){
                    longest=word;
                }else if(word.length()==longest.length() && word<longest){
                    longest=word;
                }
            }
        }
        return longest;
        
    }
};