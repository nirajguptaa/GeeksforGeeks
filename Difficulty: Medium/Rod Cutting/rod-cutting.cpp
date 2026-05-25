// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]=max(dp[i],price[j]+dp[i-j-1]);
            }
        }
        return dp[n];
    }
};