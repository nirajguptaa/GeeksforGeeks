class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        stack<int>st;
        int n=adj.size();
        vector<int>vis(n,0);
        st.push(0);
        vector<int>ans;
        
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(!vis[top]){
                vis[top]=1;
                ans.push_back(top);
                int size=adj[top].size();
                for(int i=size-1;i>=0;i--){
                    int neigh=adj[top][i];
                    if(!vis[neigh]){
                        
                        st.push(neigh);
                    }
                }
            }
        }
        return ans;
    }
};