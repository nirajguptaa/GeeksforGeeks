class Solution {
  public:
    int f(int W,int idx,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        int n=val.size();
        if(idx==n)return 0;
        if(W<0){
            return 0;
        }
        if(dp[idx][W]!=-1){
            return dp[idx][W];
        }
        int notTake=f(W,idx+1,val,wt,dp);
        int take=0;
        if(W-wt[idx]>=0){
            take=val[idx]+f(W-wt[idx],idx+1,val,wt,dp);
        }
        return dp[idx][W]=max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(W,0,val,wt,dp);
    }
};