class Solution {
  public:
    bool f(int curr,int idx,int sum,vector<int>&arr,vector<vector<int>>&dp){
        int n=arr.size();
        if(curr==sum)return true;
        if(idx==n)return false;
        if(curr>sum)return false;
        if(dp[idx][curr]!=-1){
            return dp[idx][curr];
        }
        int notTake=f(curr,idx+1,sum,arr,dp);
        int take=false;
        if(curr+arr[idx]<=sum){
            take=f(curr+arr[idx],idx+1,sum,arr,dp);
        }
        return dp[idx][curr]=notTake|| take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(0,0,sum,arr,dp);
    }
};