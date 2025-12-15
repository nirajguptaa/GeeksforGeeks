

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    vector<int>computeLPS(string s2){
        int n=s2.size();
        int i=1,len=0;
        vector<int>lps(n);
        lps[0]=0;
        while(i<n){
            if(s2[i]==s2[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool areRotations(string &s1, string &s2) {
        string txt=s1+s1;
        string pat=s2;
        vector<int>lps=computeLPS(s2);
        int n=txt.length();
        int m=pat.length();
        int i=0;
        int j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;j++;
            }
            if(j==m){
                return true;
            }
            else if(i<n && pat[j]!=txt[i]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i+=1;
                }
            }
        }
        return false;
        
        
        
        
    }
};


