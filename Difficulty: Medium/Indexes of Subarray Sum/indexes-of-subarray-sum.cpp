class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        int sum=0;
        int l=0;
        for(int r=0;r<n;r++){
            sum+=arr[r];
            if(sum>target){
                while(l<=r && sum>target){
                    sum-=arr[l];
                    l++;
                }
            }
            if(target==sum){
                return {l+1,r+1};
            }
            
        }
        return {-1};
    }
};