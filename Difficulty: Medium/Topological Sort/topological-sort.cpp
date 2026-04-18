class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>inDegree(V);
        for(auto &it:adj){
            for(auto node:it){
                inDegree[node]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            ans.push_back(ele);
            for(auto node:adj[ele]){
                inDegree[node]--;
                if(inDegree[node]==0){
                    q.push(node);
                }
            }
        }
        return ans;
    }
};