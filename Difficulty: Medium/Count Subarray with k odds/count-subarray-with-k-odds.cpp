class Solution {
  public:
  int atMost(vector<int>& arr, int k){
      int l=0,count=0,ans=0;
      int n=arr.size();
      for(int r=0;r<n;r++){
          if(arr[r]%2!=0){
            count++;
          }
        while(count>k){
            if(arr[l]%2!=0){
                count--;
            }
            l++;
        }
        ans+=(r-l+1);
                    
        
          
      }
      return ans;
  }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return atMost(arr,k)-atMost(arr,k-1);
        
    }
};