class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>>jobs;
        int n=deadline.size();
        for(int i=0;i<n;i++){
            jobs.push_back({deadline[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            if(pq.size()<jobs[i].first){
                pq.push(jobs[i].second);
            }else if(!pq.empty() && pq.top()<jobs[i].second){
                pq.pop();
                pq.push(jobs[i].second);
            } 
        }
        int count=pq.size();
        int profits=0;
        while(!pq.empty()){
            profits+=pq.top();
            pq.pop();
        }
        return {count,profits};
        
    }
};