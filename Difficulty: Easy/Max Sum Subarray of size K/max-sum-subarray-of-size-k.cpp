class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int maxSum=0;
        int l=0,n=arr.size();
        int currSum=0;
        for(int r=0;r<n;r++){
            if(r-l+1>k){
                currSum-=arr[l];
                l++;
            }
            currSum+=arr[r];
            maxSum=max(maxSum,currSum);
        }
        return maxSum;
    }
};