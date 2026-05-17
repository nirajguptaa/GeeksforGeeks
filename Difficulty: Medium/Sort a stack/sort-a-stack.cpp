class Solution {
  public:
  void insertSorted(stack<int>&st,int x){
      if(st.empty() || x>st.top()){
          st.push(x);
          return;
      }
      int topEle=st.top();
      st.pop();
      insertSorted(st,x);
      st.push(topEle);
  }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return ;
        }
        int topEle=st.top();
        st.pop();
        sortStack(st);
        insertSorted(st,topEle);
    }
};
