class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            pq.push({mat[i][0],{i,0}});
        }
        
        while(k>1){
            auto top=pq.top();
            pq.pop();
            int i=top.second.first;
            int j=top.second.second;
            if(j+1<m){
                pq.push({mat[i][j+1],{i,j+1}});
            }
            k--;
            
        }
        return pq.top().first;
    }
};
