class Solution {
  public:
  bool safe(vector<int>&vis,int node,int col,vector<int>Adj[]){
      for(auto it:Adj[node]){
          if(vis[it]==col){
              return false;
          }
      }
      return true;
  }
  bool f(int node,int v,vector<int>&vis,int m,vector<int>Adj[]){
      if(node==v)return true;
      for(int col=1;col<=m;col++){
          if(safe(vis,node,col,Adj)){
              vis[node]=col;
              if(f(node+1,v,vis,m,Adj)){
                  return true;
              }
              vis[node]=0;
          }
      }
      return false;
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int>Adj[v];
        for(auto &e:edges){
            int u=e[0];
            int vv=e[1];
            Adj[u].push_back(vv);
            Adj[vv].push_back(u);
        }
        vector<int>vis(v);
        return f(0,v,vis,m,Adj);
    }
};