// User function Template for C++
class Disjoint{
    vector<int>parent,size;
    public:
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
             parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {//u v wt
        
        // sort(edges.begin(),edges.end(),
        //     [](auto &a,auto &b){return a[2]<b[2];} 
        // );
        
        sort(edges.begin(),edges.end(),cmp);
        Disjoint ds(V);
        int mstWt=0;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt+=w;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
    
};