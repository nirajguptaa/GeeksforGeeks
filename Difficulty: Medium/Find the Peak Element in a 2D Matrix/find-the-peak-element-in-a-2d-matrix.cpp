class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int maxRow=0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mat[maxRow][mid]){
                    maxRow=i;
                }
            }
            int left=(mid>0)?mat[maxRow][mid-1]:INT_MIN;
            int right=(mid<m-1)?mat[maxRow][mid+1]:INT_MIN;
            if(mat[maxRow][mid]>=left && mat[maxRow][mid]>=right){
                return {maxRow,mid};
            }else if(left>mat[maxRow][mid]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};
