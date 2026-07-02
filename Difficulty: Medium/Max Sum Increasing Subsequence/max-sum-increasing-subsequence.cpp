class Solution {
  public:
    int maxSumIS(vector<int>& nums) {
        // code here
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=nums[i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],nums[i]+dp[j]);
                    
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};