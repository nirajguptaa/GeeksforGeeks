class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int first=0,last=n-1;
        for(int i=0;i<n;i++){
            int temp=mat[i][first];
            mat[i][first]=mat[i][last];
            mat[i][last]=temp;
            first++;
            last--;
            
        }
    }
};
