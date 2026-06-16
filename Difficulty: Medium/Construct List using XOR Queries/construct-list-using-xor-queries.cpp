class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int>ans;
        ans.push_back(0);
        int xo=0;
        for(auto q:queries){
            
            if(q[0]==0){
                ans.push_back(q[1]^xo);
            }else if(q[0]==1){
                int x=q[1];
                xo^=x;
                
                
            }
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=ans[i]^xo;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
