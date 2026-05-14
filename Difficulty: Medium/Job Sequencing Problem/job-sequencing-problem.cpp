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
        int count=0,totalprofit=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            if(pq.size()<jobs[i].first){
                pq.push(jobs[i].second);
            }else{
                if(!pq.empty() && pq.top()<jobs[i].second){
                    pq.pop();
                    pq.push(jobs[i].second);
                }
            }
        }
        count=pq.size();
        while(!pq.empty()){
            totalprofit+=pq.top();
            pq.pop();
        }
        return {count,totalprofit};
        
    }
};