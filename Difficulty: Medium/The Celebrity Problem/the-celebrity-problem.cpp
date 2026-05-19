class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<bool>celeb(n,true);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(mat[i][j]==1){
                    celeb[i]=false;
                    
                }
                if(mat[i][j]==0){
                    celeb[j]=false;

                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(celeb[i]){
                
                return i;
            }
        }
        
        return -1;
    }
};