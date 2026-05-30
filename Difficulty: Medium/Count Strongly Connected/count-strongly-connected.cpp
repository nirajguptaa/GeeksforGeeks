class Solution {
  public:
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
        }
        st.push(node);
    }
    void dfs1(int node,vector<int>&vis,vector<int>revAdj[]){
        vis[node]=1;
        for(auto it:revAdj[node]){
            if(!vis[it]){
                dfs1(it,vis,revAdj);
            }
        }
        
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adj[V];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>vis(V);
        stack<int>st;
        // Step 1: DFS and store nodes in stack
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        // Step 2: Reverse graph
        vector<int>revAdj[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                revAdj[it].push_back(i);
            }
        }
       int scc=0;
        // Step 3: Count SCCs
       while(!st.empty()){
           int node=st.top();
           st.pop();
           if(!vis[node]){
               scc++;
               dfs1(node,vis,revAdj);
           }
       }
        
        return scc;
        
    }
};