class Solution {
  public:
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
        vis[node]=1;
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,vis,st,adj);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>vis(V);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int>topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
        
    }
};