class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        
       
        vector<int>indegree(V);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>topoSortArr;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
            
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topoSortArr.push_back(node);
            for(int neigh:adj[node]){
                
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
                
            }
        }
        return topoSortArr; 
        
        
    }
};