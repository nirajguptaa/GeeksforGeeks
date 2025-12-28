class Solution {
  public:
  bool possible(int m,vector<int>& ranks, int n){
      int sum=0;
      for(int i=0;i<ranks.size();i++){
          int r=ranks[i];
          int k=(int)((-1+sqrt(1+8.0*m/r))/2);
          sum+=k;
          if(sum>=n)return true;
      }
      return false;
  }
    int minTime(vector<int>& ranks, int n) {
        // code here
        int r=*min_element(ranks.begin(),ranks.end());
        int maxTime=r*n*(n+1)/2;
        int l=0,h=maxTime;
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(mid,ranks,n)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};
        
        