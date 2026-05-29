class Solution {
  public:
     void lps(string text,vector<int>&lpsArray){
        lpsArray[0]=0;
        int i=1,len=0;
        while(i<text.size()){
            if(text[i]==text[len]){
                len++;
                lpsArray[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lpsArray[len-1];
                }else{
                    len=0;
                    i++;
                }
            }
        }

    }
    vector<int> search(string &pat, string &txt) {
        // code here
        int p=pat.size(),n=txt.size();
        vector<int>lpsArray(p);
        vector<int>res;
        lps(pat,lpsArray);
        int i=0,j=0;
        while(i<n){
           if(txt[i]==pat[j]){
                i++;
                j++;
                if(j==p){
                    res.push_back(i-j);
                    j=lpsArray[j-1];    
                }
           }else{
               if(j!=0){
                   j=lpsArray[j-1];
               }else{
                   i++;
               }
           }
           
        }
        return res;
    }
};