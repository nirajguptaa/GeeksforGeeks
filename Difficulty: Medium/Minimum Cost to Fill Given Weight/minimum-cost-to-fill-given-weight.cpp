class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n=cost.size();
        vector<int>dp(w+1,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(cost[i]==-1){
                continue;
            }
            int wt=i+1;
            for(int curr=wt;curr<=w;curr++){
                dp[curr]=min(dp[curr],dp[curr-wt]+cost[i]);
            }
        }
        if(dp[w]==1e9){
            return -1;
        }else{
            return dp[w];
        }
    }
};
