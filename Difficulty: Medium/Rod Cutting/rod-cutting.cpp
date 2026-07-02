class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int len=price.size();
        vector<int>dp(len+1,0);
        for(int i=0;i<=len;i++){
            for(int j=0;j<i;j++){
                dp[i]=max(dp[i],price[j]+dp[i-j-1]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};