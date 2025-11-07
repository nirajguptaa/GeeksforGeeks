class Solution {
  public:
  void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&res){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(it,adj,vis,res);
          }
      }
      res.push_back(node);
      
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
       
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(V,0);
        vector<int>res;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,res);
            }
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};