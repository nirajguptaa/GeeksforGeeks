class Solution {
    bool isPowerofTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
  public:
        
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int len=s.size();
        if(isPowerofTwo(len)){
            k/=2;
        }else{
            k*=2;
        }
        if(k>=len){
            return "-1";
        }
        int targetlen=len-k;
        string st;
        for(int i=0;i<len;i++){
            while(!st.empty() && st.back()>s[i] && st.size()-1+(len-i)>=targetlen){
                st.pop_back();
            }
            if(st.size()<targetlen){
                
                st+=s[i];
            }
        }
        
        return st;
    }
};