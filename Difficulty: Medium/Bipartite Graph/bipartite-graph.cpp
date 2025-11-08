class Solution {
  public:
  bool bfs(int node,vector<int>adj[],vector<int>&col){
      queue<int>q;
      q.push(node);
      col[node]=0;
      while(!q.empty()){
          int nodde=q.front();
          q.pop();
          
          for(auto it:adj[nodde]){
              if(col[it]==-1){
                  col[it]=!col[nodde];
                  q.push(it);
              }
              else if(col[it]==col[nodde]){
                  return false;
              }
          }
      }
      return true;
  }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>col(V,-1);
        
        
        for(int i=0;i<V;i++){
            if(col[i]==-1){
                if(!bfs(i,adj,col)){
                    return false;
                }
            }
            
        }
        return true;
    }
};