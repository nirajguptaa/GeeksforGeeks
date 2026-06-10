class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n=s.size();
        vector<int>open(n+1,0);
        vector<int>close(n+1,0);
       
        for(int i=1;i<=n;i++){
            if(s[i-1]=='('){
                open[i]=1+open[i-1];
            }else{
                open[i]=open[i-1];
            }
            
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                close[i]=1+close[i+1];
            }else{
                close[i]=close[i+1];
            }
            
        }
        for(int i=0;i<=n;i++){
            
            if(open[i]==close[i]){
                return i;
            }
        }
        return 0;
    }
};