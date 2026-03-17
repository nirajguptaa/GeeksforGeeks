class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n=adj.size();
        vector<int>vis(n,0);
        stack<int>St;
        int start=0;
        St.push(start);
        
        while(!St.empty()){
            int node=St.top();
            St.pop();
            
            if(!vis[node]){
                vis[node]=1;
                ans.push_back(node);
                for(int i=adj[node].size()-1;i>=0;i--){
                    int it=adj[node][i];
                    if(!vis[it]){
                        St.push(it);
                        
                    }
                }
            }
        
        }
        return ans;
    }
};

