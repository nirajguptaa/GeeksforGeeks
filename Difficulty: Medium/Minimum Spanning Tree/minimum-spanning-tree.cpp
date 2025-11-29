class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});//wt ,node
        int totalWt=0;
        while(!pq.empty()){
            int currWt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            totalWt+=currWt;
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;
                if(!vis[adjNode]){
                    pq.push({edgeWt,adjNode});
                }
                
            }
        }
        return totalWt;
        
    }
};