class Solution {
  public:
    int f(int ind,int W, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[ind]<=W){
                return val[ind];
                
            }
            return 0;
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W];
        }
        int notpick=f(ind-1,W,val,wt,dp);
        int pick=0;
        if(wt[ind]<=W){
            pick=val[ind]+f(ind-1,W-wt[ind],val,wt,dp);
        }
        return dp[ind][W]=max(pick,notpick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,W,val,wt,dp);
        
    }
};