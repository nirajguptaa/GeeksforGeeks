class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n=adj.size();
        
        vector<int>vis(n,0);
        stack<int>st;
        st.push(0);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                vis[node]=1;
                ans.push_back(node);
                for(int i=adj[node].size()-1;i>=0;i--){
                    int it=adj[node][i];
                    if(!vis[it]){
                        st.push(it);
                    
                    }
                }
            }
            
        }
        return ans;
    }
};