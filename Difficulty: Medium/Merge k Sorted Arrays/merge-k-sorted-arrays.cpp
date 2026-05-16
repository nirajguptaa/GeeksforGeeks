class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            pq.push({mat[i][0],{i,0}});
        }
        vector<int>ans;
        while(!pq.empty()){
            int ele=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            ans.push_back(ele);
            pq.pop();
            if(j+1<m){
                pq.push({mat[i][j+1],{i,j+1}});
            }
            
        }
        return ans;
    }
};