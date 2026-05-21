
class Solution {
  public:
    int sumoflength(vector<int>& nums) {
        // code
        int n=nums.size();
        int ans=0;
        int mod=1e9+7;
        int left=0;
        unordered_map<int,int>mp;
        for(int right=0;right<n;right++){
            mp[nums[right]]++;
            while(mp[nums[right]]>1){
                mp[nums[left]]--;
                left++;
            }
            int len=right-left+1;
            ans=(ans+len*(len+1)/2)%mod;
        }
        return ans;
        
    }
};