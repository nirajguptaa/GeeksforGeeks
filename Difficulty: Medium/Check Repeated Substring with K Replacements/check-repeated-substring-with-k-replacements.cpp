class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n=s.size();
        if(n%k!=0){
            return false;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i+=k){
            string curr=s.substr(i,k);
            mp[curr]++;
        }
        int blocks=n/k;
        int mx=0;
        for(auto &it:mp){
            mx=max(mx,it.second);
        }
        return (blocks-mx)<=1;
        
    }
};