class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n=s1.size(),m=s2.size();
        int i=0;
        string ans="";
        int minLen=INT_MAX;
        while(i<n){
            int j=0;
            while(i<n && j<m){
                if(s1[i]==s2[j])j++;
                i++;
            }
            
            if(j<m)break;
            int e1=i-1;
            j=m-1;
            
            while(j>=0){
                if(s1[e1]==s2[j]){
                    j--;
                }
                e1--;
            }
            e1++;
            if(i-e1<minLen){
                minLen=i-e1;
                ans=s1.substr(e1,minLen);
            }
            
            i=e1+1;
            
        }
        return ans;
    }
};
