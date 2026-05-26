class Solution {
  public:
    int f(int idx,int W,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(idx==wt.size()){
            return 0;
        }
        
        if(dp[idx][W]!=-1){
            return dp[idx][W];
        }
        int notake=f(idx+1,W,val,wt,dp);
        int take=0;
        if((W-wt[idx])>=0){
            take=val[idx]+f(idx+1,W-wt[idx],val,wt,dp);
        }
        return dp[idx][W]=max(take,notake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(0,W,val,wt,dp);
    }
};