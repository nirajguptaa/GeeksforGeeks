class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>q;
        vector<int>ans;
        
        for(int a:arr){
            q.push(a);
            while(q.size()>k){
                q.pop();
            }
            if(q.size()==k){
                ans.push_back(q.top());
                
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};