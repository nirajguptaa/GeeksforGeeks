class Solution {
  public:
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>>adj[V];
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>parent(V,0);
        vector<int>path(V,1e9);
        path[src]=0;
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});//dist src
        while(!pq.empty()){
            int currDist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(currDist>path[node])continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjDist=it.second;
                if(currDist+adjDist<path[adjNode]){
                    path[adjNode]=currDist+adjDist;
                    pq.push({adjDist+currDist,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        return path;
    }
};