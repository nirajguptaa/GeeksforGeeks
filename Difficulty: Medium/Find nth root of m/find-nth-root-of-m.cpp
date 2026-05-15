class Solution {
  public:
    int power(int mid,int n,int m){
        int ans=1;
        for(int i=0;i<n;i++){
            ans*=mid;
        }
        return ans;
    }
    int nthRoot(int n, int m) {
        // Code here
        int l=0,h=m;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(power(mid,n,m)==m){
                return mid;
            }else if(power(mid,n,m)>m){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
        
    }
};