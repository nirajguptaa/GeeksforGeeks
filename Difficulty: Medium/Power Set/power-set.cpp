class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>subseq;
        int n=s.size();
        for(int i=0;i<(1<<n);i++){
            string curr="";
            for(int j=0;j<n;j++){
                if((1<<j) & i){
                    
                    curr+=s[j];
                }
            }
            subseq.push_back(curr);
        }
        sort(subseq.begin(),subseq.end());
        return subseq;
        
    }
};