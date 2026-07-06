class Solution {
  public:
    void f(int open,int close,int size,string curr,vector<string>&ans){
        if(open==size && close==size){
            ans.push_back(curr);
            return;
        }
        
            
        if(close>open){
            return;
        }
        if(open<size){
            
            curr.push_back('(');
            f(open+1,close,size,curr,ans);
            curr.pop_back();
        }
        if(close<size){
            
            curr.push_back(')');
            f(open,close+1,size,curr,ans);
            curr.pop_back();
        }
        
    }
    vector<string> generateParentheses(int n) {
        // code here
        vector<string>ans;
        if(n%2!=0)return ans;
        f(0,0,n/2,"",ans);
        return ans;
    }
};