class Solution {
  public:
    int lessThan(int m,vector<int>&arr){
        return upper_bound(arr.begin(),arr.end(),m)-arr.begin();
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int l=1,h=1e9;
        int req=(m*n+1)/2;
        while(l<=h){
            int m=l+(h-l)/2;
            int count=0;
            for(int i=0;i<n;i++){
                count+=lessThan(m,mat[i]);
            }
            if(count<req){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return l;
    }
};
