class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int len=s.size();
       
        int ans=-1;
        int i=0;
        while(i<len && s[i]=='1'){
            i++;
        }
        int curr=0;
        for(int k=i;k<len;k++){
            if(curr<0)curr=0;
            if(s[k]=='0'){
               curr++;
               ans=max(curr,ans);
            }else{
                curr--;
            }
        }
        
        return ans;
    }
};