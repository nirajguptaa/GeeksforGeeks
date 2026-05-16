class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({a[0]+b[0],{0,0}});
        set<pair<int,int>>vis;
        vector<int>ans;
        while(!pq.empty() && k--){
            int sum=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            ans.push_back(sum);
            pq.pop();
            vis.insert({i,j});
            if(i+1<a.size() && vis.find({i+1,j})==vis.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                vis.insert({i+1,j});
            }
            if(j+1<b.size() && vis.find({i,j+1})==vis.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                vis.insert({i,j+1});
            }
        }
        return ans;
        
    }
};