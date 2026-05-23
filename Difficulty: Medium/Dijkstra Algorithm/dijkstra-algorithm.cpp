class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //shortest distance form sorce to every node
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>path(V,INT_MAX);
        path[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto node=pq.top();
            int dist=node.first;
            int start=node.second;
            pq.pop();
            if(dist>path[start])continue;
            for(auto neigh:adj[start]){
                int adjNode=neigh.first;
                int adjWt=neigh.second;
                if(dist+adjWt<path[adjNode]){
                    path[adjNode]=dist+adjWt;
                    pq.push({dist+adjWt,adjNode});
                }
            }
        }
        return path;
    }
};