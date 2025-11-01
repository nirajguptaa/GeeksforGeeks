class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>Ans;
        queue<int>q;
        int n=adj.size();
        vector<int>vis(n,0);
        int start=0;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int node=q.front();
            Ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return Ans;
    }
};