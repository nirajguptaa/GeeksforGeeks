class Solution {
  public:
    int lowerEqual(int m,vector<int>arr){
        return upper_bound(arr.begin(),arr.end(),m)-arr.begin();
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int req=(n*m+1)/2;
        int l=1,h=1e9;
        while(l<=h){
            int m=l+(h-l)/2;
            int count=0;
            for(int i=0;i<n;i++){
                count+=lowerEqual(m,mat[i]);
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
