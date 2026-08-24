class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        vector<int>ans;
        set<pair<int,int>>vis;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({a[0]+b[0],{0,0}});
        while(!pq.empty() && k--){
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            ans.push_back(val);
            vis.insert({row,col});
            while(row+1<a.size() && vis.find({row+1,col})==vis.end()){
                pq.push({a[row+1]+b[col],{row+1,col}});
                vis.insert({row+1,col});
            }
            while(col+1<b.size() && vis.find({row,col+1})==vis.end()){
                pq.push({a[row]+b[col+1],{row,col+1}});
                vis.insert({row,col+1});
            }
        }
        return ans;
    }
};