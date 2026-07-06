class Solution {
  public:
    bool dfs(int node,int par,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,node,vis,adj)){
                    return true;
                }
                
            }else if(it!=par){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        vector<int>vis(V);
       
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};