// User function Template for C++
class Disjoint{
    private:
    vector<int>parent,size;
    public:
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]); 
    }
    void unionSize(int u,int v){
        int ultP_U=findUPar(u);
        int ultP_V=findUPar(v);
        if(ultP_U==ultP_V)return;
        if(size[ultP_U]<size[ultP_V]){
            parent[ultP_U]=ultP_V;
            size[ultP_V]+=size[ultP_U];
        }else{
            parent[ultP_V]=ultP_U;
            size[ultP_U]+=size[ultP_V];
        }
    }
};
class Solution {
  public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[2]<b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),cmp);
        Disjoint d(V);
        int ans=0;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            if(d.findUPar(u)!=d.findUPar(v)){
                ans+=wt;
                d.unionSize(u,v);
            }
        }
        return ans;
    }
};