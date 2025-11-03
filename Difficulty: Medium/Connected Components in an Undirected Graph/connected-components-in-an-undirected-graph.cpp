class Solution {
  public:
  void bfs(int ele,vector<int>&vis,vector<int>adj[],vector<int>&comp){
      queue<int>q;
      q.push(ele);
      vis[ele]=1;
        while(!q.empty()){
            
            int top=q.front();
            q.pop();
            comp.push_back(top);
            for(auto it:adj[top]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>ans;
        vector<int>vis(V,0);
        vector<int>adj[V];
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int>comp;
                bfs(i,vis,adj,comp);
                ans.push_back(comp);
            }
        }
        
        
        return ans;
    }
};
